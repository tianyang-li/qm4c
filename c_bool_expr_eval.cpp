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

#include "c_bool_expr_eval.h"
#include "parse_c_bool_expr.h"

CBoolExprEval::CBoolExprEval() {
	expr_var_["0"] = false;
	expr_var_["1"] = true;
}

void CBoolExprEval::InitEvalStruct(const std::string &expr_to_eval) {
}

bool CBoolExprEval::BinEvalNode::DoEval() {
	switch (this->op_type_) {
		case OP_AND_:
			return (left_->DoEval() && right_->DoEval());
			break;
		case OP_OR_:
			return (left_->DoEval() || right_->DoEval());
			break;
	}
}

bool CBoolExprEval::UniEvalNode::DoEval() {
	switch (this->op_type_) {
		case OP_NOT_:
			return !input_->DoEval();
			break;
		case OP_NOTHING_:
			return var_val_->find(node_expr_)->second;
			break;
	}
}

CBoolExprEval::BinEvalNode::BinEvalNode()
	: left_(0), 
	right_(0) {
}

CBoolExprEval::UniEvalNode::UniEvalNode() 
	: input_(0),
	var_val_(0) {
}