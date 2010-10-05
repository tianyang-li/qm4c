/*
 *  Copyright (C) 2010 Tianyang Li
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author Tianyang Li 
 * E-Mail tmy1018 gmail com
 */

#include "eval_bool_expr.h"

ExprNode::ExprNode()
: op_(OP_VAR), left_(0), right_(0) {
}

bool ExprNode::DoEval(std::map<std::string, bool> const &var_val,
					  std::string const &expr_str) {
	switch (op_) {
		case OP_OR:
			return left_->DoEval(var_val, expr_str) || right_->DoEval(var_val, expr_str);
			break;
		case OP_AND:
			return left_->DoEval(var_val, expr_str) && right_->DoEval(var_val, expr_str);
			break;
		case OP_NOT:
			return !left_->DoEval(var_val, expr_str);
			break;
		case OP_PAR:
			return left_->DoEval(var_val, expr_str);
			break;
		case OP_VAR:
			return var_val.find(expr_str.substr(expr_loc_.first, expr_loc_.second - expr_loc_.first + 1))->second;
			break;
	}
}

EvalBoolExpr::EvalBoolExpr(std::map<std::string, bool> const &var_map, 
						   std::string const &expr_str)
: expr_var_(&var_map), input_str_(&expr_str) {
}

bool EvalBoolExpr::InitBuildEvalStruct(unsigned int expr_begin, unsigned int expr_end,
									   ExprNode *&child) {
	if (expr_begin > expr_end) {
		return false;
	}

	ExprNode temp_expr_node;
	temp_expr_node.expr_loc_ = std::make_pair(expr_begin, expr_end);
	expr_parse_.push_back(temp_expr_node);
	child = &expr_parse_.back();

	// location to separate
	// for   OP_OR  OP_AND		(expr_begin, sep_loc)		(sep_loc + 1, expr_end)
	unsigned int sep_loc; 

	// check for parentheses 
	// make it function like a stack 
	// it's like a depth
	std::vector<unsigned int> par_stack;

	// processing
	// i have to go backward
	for (unsigned int i = 0; i != expr_end - expr_begin + 1; ++i) {
		// because i is unsigned int
		// so be careful when writing certain statements
		// the hard part
		switch (input_str_->at(expr_end - i)) {
			// set i = expr_end to break out of the loop? better not
			case '|':
				if (!par_stack.size()) {
					++i;
					if (temp_expr_node.op_ != ExprNode::OP_OR) {
						sep_loc = expr_end - i;
						temp_expr_node.op_ = ExprNode::OP_OR;
					}
				}
				break;

			case '&':
				if (!par_stack.size()) {
					++i;
					if (temp_expr_node.op_ != ExprNode::OP_OR 
						&& temp_expr_node.op_ != ExprNode::OP_AND) {
						sep_loc = expr_end - i;
						temp_expr_node.op_ = ExprNode::OP_AND;
					}
				}
				break;

			case '~':
				if (!par_stack.size()) {
					if (temp_expr_node.op_ != ExprNode::OP_OR
						&& temp_expr_node.op_ != ExprNode::OP_AND) {
							temp_expr_node.op_ = ExprNode::OP_NOT;
							sep_loc = expr_end - i;
					}
				}
				break;

			case ')':
				par_stack.push_back(expr_end - i);
				break;

			case '(':
				// par check OP_PAR
				if (i == expr_end - expr_begin
					&& par_stack.back() == expr_end) {
						temp_expr_node.op_ = ExprNode::OP_PAR;
				}
				break;

			default:
				break;
		}
	}

	switch (temp_expr_node.op_) {
		// separate at ||
		case ExprNode::OP_OR:
			return InitBuildEvalStruct(expr_begin, sep_loc, expr_parse_.back().left_) 
				&& InitBuildEvalStruct(sep_loc + 1, expr_end, expr_parse_.back().right_);
			break;

		// separate at &&
		case ExprNode::OP_AND:
			return InitBuildEvalStruct(expr_begin, sep_loc, expr_parse_.back().left_) 
				&& InitBuildEvalStruct(sep_loc + 1, expr_end, expr_parse_.back().right_);
			break;

		// strips away ~
		case ExprNode::OP_NOT:
			return InitBuildEvalStruct(expr_begin + 1, expr_end, expr_parse_.back().left_);
			break;

		// strips away ( )
		case ExprNode::OP_PAR:
			if (expr_begin + 1 == expr_end) {
				return false;
			}
			return InitBuildEvalStruct(expr_begin + 1, expr_end - 1, expr_parse_.back().left_);
			break;

		case ExprNode::OP_VAR:
			break;
	}

	return true;
}


