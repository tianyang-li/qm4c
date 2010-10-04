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

// evaluate a boolean epression when each varaible's value's give

#ifndef QM4C_C_BOOL_EXPR_EVAL_H_
#define QM4C_C_BOOL_EXPR_EVAL_H_

#include <string>
#include <map>
#include <iostream>

class CBoolExprEval {
public:
	CBoolExprEval();
	// init the evaluation structure so it can be used
	// more the once
	void InitEvalStruct(std::string const &expr_to_eval);

private:
	// used as nodes where evaluation can be done
	// this serves as a base
	class EvalNode {
	public:
		virtual bool DoEval() = 0;

	protected:
		// EvalNode operator type
		enum OpType {OP_AND_, OP_OR_, OP_NOT_, OP_NOTHING_};
		// OP_AND_ is for &&
		// OP_OR_ is for ||
		// OP_NOT_ is for ~
		// OP_NOTHING_ is for nothing (so just get the value of the variable)
		OpType op_type_;
		// the boolean expression this node has to evaluate
		std::string node_expr_;  
	};
	
	// for unary operations (~ and doing nothing)
	class UniEvalNode: public CBoolExprEval::EvalNode {
		// TODO: can public be changed to private?
	public:
		UniEvalNode();

	protected:
		bool DoEval();
		// left and right operand
		CBoolExprEval::EvalNode *input_;
		// remember to point this to expr_var when needed
		std::map<std::string, bool> const *var_val_;
	};

	// for binary operations (&& ||)
	class BinEvalNode: public CBoolExprEval::EvalNode {
		// TODO: can public be changed to private?
	public:
		BinEvalNode();

	protected:
		bool DoEval();
		// input into this node
		CBoolExprEval::EvalNode *left_, *right_;
	};

	// a map that stores the value of each variable in the input expression
	//  ("0", false) ("1", true) are added in the constructor
	std::map<std::string, bool> expr_var_;

};

#endif  // QM4C_C_BOOL_EXPR_EVAL_H_