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

void CBoolExprEval::InitEvalStruct(const std::string &expr_to_eval) {
}

bool CBoolExprEval::BinEvalNode::DoEval() {
	bool node_val;
	return node_val;
}

bool CBoolExprEval::UniEvalNode::DoEval() {
	bool node_val;
	return node_val;
}

CBoolExprEval::BinEvalNode::BinEvalNode()
	: left_(0), 
	right_(0) {
}

CBoolExprEval::UniEvalNode::UniEvalNode() 
	: input_(0) {
}