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

EvalBoolExpr::EvalBoolExpr(std::map<std::string, bool> const &var_map, 
						   std::string const &expr_str)
: expr_var_(&var_map), input_str_(&expr_str) {
}

/*
bool EvalBoolExpr::InitBuildEvalStruct() {
	EvalNode cur_expr(*expr_var_, *input_str_);
	if (!cur_expr.InitSetExprLoc(0, input_str_->length() - 1)) {
		return false;
	}

	expr_tree_.push_back(cur_expr);
	return true;
}

bool EvalBoolExpr::EvalNode::InitSetExprLoc(unsigned int expr_begin, 
											unsigned int expr_end) {
	// stores each pair of parentheses
	std::vector< std::pair<unsigned int, unsigned int> > temp_par_pair;

	for (unsigned int i = expr_begin; i <= expr_end; ++i) {
	}

	// TODO: expr processing

	EvalNode temp_eval_node(var;
	switch (node_op_) {
		case OP_VAR_:
			break;
		case OP_PAR_:
			// check for empty parenthesis, sth like ()
			if (expr_begin + 1 == expr_end) {
				return false;
			}
			temp_eval_node

			break;
	}
	
	return true;
}

bool EvalBoolExpr::EvalNode::DoEval() {
	switch (node_op_) {
		case OP_AND_:
			return left_->DoEval() && right_->DoEval();
			break;

		case OP_OR_:
			return left_->DoEval() || right_->DoEval();
			break;

		case OP_NOT_:
			return !left_->DoEval();
			break;

		case OP_PAR_:
			return left_->DoEval();
			break;

		case OP_VAR_:
			return node_expr_var_->find(node_input_str_->substr(expr_loc_.first, 
				expr_loc_.second - expr_loc_.first + 1))->second;
			break;
	}
}

EvalBoolExpr::EvalNode::EvalNode(std::map<std::string, bool> const &var_val,
								 std::string const &expr_str) 
: left_(0), right_(0), node_op_(OP_VAR_),
node_expr_var_(&var_val), node_input_str_(&expr_str) {
}
*/


