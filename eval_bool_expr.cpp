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

bool EvalBoolExpr::InitBuildEvalStruct(unsigned int expr_begin, unsigned int expr_end) {
	ExprNode temp_expr_node;
	temp_expr_node.expr_loc_ = std::make_pair(expr_begin, expr_end);
	expr_parse_.push_back(temp_expr_node);

	// location to separate
	// for   OP_OR  OP_AND		(expr_begin, sep_loc)		(sep_loc + 1, expr_end)
	unsigned int sep_loc; 

	// TODO: processing

	switch (temp_expr_node.op_) {
		case ExprNode::OP_OR:
			return InitBuildEvalStruct(expr_begin, sep_loc) 
				&& InitBuildEvalStruct(sep_loc + 1, expr_end);
			break;

		case ExprNode::OP_AND:
			return InitBuildEvalStruct(expr_begin, sep_loc) 
				&& InitBuildEvalStruct(sep_loc + 1, expr_end);
			break;

		case ExprNode::OP_NOT:
			return InitBuildEvalStruct(expr_begin + 1, expr_end);
			break;

		// strips away ( )
		case ExprNode::OP_PAR:
			if (expr_begin + 1 == expr_end) {
				return false;
			}
			return InitBuildEvalStruct(expr_begin + 1, expr_end - 1);
			break;

		case ExprNode::OP_VAR:
			break;
	}

	return true;
}


