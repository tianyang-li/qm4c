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

#include <cctype>

#include "eval_bool_expr.h"

ExprNode::ExprNode()
: op_(OP_VAR), left_(0), right_(0) {
}

bool ExprNode::DoEval(std::map<std::string, bool> const &var_val,
					  std::string const &expr_str,
					  std::vector<ExprNode> const &token) const {
	switch (op_) {
		case OP_OR:
			return token[left_].DoEval(var_val, expr_str, token) || token[right_].DoEval(var_val, expr_str, token);
			break;

		case OP_AND:
			return token[left_].DoEval(var_val, expr_str, token) && token[right_].DoEval(var_val, expr_str, token);
			break;

		case OP_NOT:
			return !token[left_].DoEval(var_val, expr_str, token);
			break;

		case OP_PAR:
			return token[left_].DoEval(var_val, expr_str, token);
			break;

		case OP_VAR:
			return var_val.find(expr_str.substr(expr_loc_.first, expr_loc_.second - expr_loc_.first + 1))->second;
			break;
	}
}

EvalBoolExpr::EvalBoolExpr(std::string const &expr_str)
: input_str_(&expr_str) {
}

bool EvalBoolExpr::InitBuildEvalStruct(unsigned int expr_begin, unsigned int expr_end,
									   bool side, ExprNode &par) {
	if (expr_begin > expr_end) {
		return false;
	}

	if (side) {
		par.right_ = expr_parse_.size();
	}
	else {
		par.left_ = expr_parse_.size();
	}

	ExprNode temp_expr_node;
	temp_expr_node.expr_loc_ = std::make_pair(expr_begin, expr_end);
	expr_parse_.push_back(temp_expr_node);

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
				++i;
				if (input_str_->at(expr_end - i) != '|') {
					return false;
				}
				if (!par_stack.size()) {
					if (expr_parse_[expr_parse_.size() - 1].op_ != ExprNode::OP_OR) {
						sep_loc = expr_end - i;
						expr_parse_[expr_parse_.size() - 1].op_ = ExprNode::OP_OR;
					}
				}
				break;

			case '&':
				++i;
				if (input_str_->at(expr_end - i) != '&') {
					return false;
				}
				if (!par_stack.size()) {
					if (expr_parse_[expr_parse_.size() - 1].op_ != ExprNode::OP_OR 
						&& expr_parse_[expr_parse_.size() - 1].op_ != ExprNode::OP_AND) {
						sep_loc = expr_end - i;
						expr_parse_[expr_parse_.size() - 1].op_ = ExprNode::OP_AND;
					}
				}
				break;

			case '!':
				if (!par_stack.size()) {
					if (expr_parse_[expr_parse_.size() - 1].op_ != ExprNode::OP_OR
						&& expr_parse_[expr_parse_.size() - 1].op_ != ExprNode::OP_AND) {
							expr_parse_[expr_parse_.size() - 1].op_ = ExprNode::OP_NOT;
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
						expr_parse_[expr_parse_.size() - 1].op_ = ExprNode::OP_PAR;
				}
				par_stack.pop_back();
				break;

			default:
				break;
		}
	}

	// recursion
	unsigned cur_index = expr_parse_.size() - 1;
	switch (expr_parse_[expr_parse_.size() - 1].op_) {
		// side: false - left; true - right
		// separate at ||
		case ExprNode::OP_OR:
			return InitBuildEvalStruct(expr_begin, sep_loc - 1, false, expr_parse_[cur_index]) 
				&& InitBuildEvalStruct(sep_loc + 2, expr_end, true, expr_parse_[cur_index]);
			break;

		// separate at &&
		case ExprNode::OP_AND:
			return InitBuildEvalStruct(expr_begin, sep_loc - 1, false, expr_parse_[cur_index]) 
				&& InitBuildEvalStruct(sep_loc + 2, expr_end, true, expr_parse_[cur_index]);
			break;

		// strips away ~
		case ExprNode::OP_NOT:
			return InitBuildEvalStruct(expr_begin + 1, expr_end, false, expr_parse_[cur_index]);
			break;

		// strips away ( )
		case ExprNode::OP_PAR:
			if (expr_begin + 1 == expr_end) {
				return false;
			}
			return InitBuildEvalStruct(expr_begin + 1, expr_end - 1, false, expr_parse_[expr_parse_.size() - 1]);
			break;

		case ExprNode::OP_VAR:
			break;
	}

	return true;
}

bool EvalBoolExpr::EvalResult(const std::map<std::string,bool> &var_val) {
	return expr_parse_[0].DoEval(var_val, *input_str_, expr_parse_);
}

void EvalBoolExpr::InitPrep() {
	expr_parse_.clear();
}

