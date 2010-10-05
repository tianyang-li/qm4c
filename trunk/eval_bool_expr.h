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

// the input expression is already 
// processed by SimplifyBoolExpr::InitCheckInput()
// input_str_ can't point to an empty string

#ifndef QM4C_EVAL_BOOL_EXPR_H_
#define QM4C_EVAL_BOOL_EXPR_H_

#include <map>
#include <string>
#include <vector>
#include <utility>

class EvalBoolExpr;

class ExprNode {
	friend class EvalBoolExpr;

public:
	ExprNode();

	// in order of increasing precedence
	enum NodeType {OP_OR, OP_AND, OP_NOT, OP_PAR, OP_VAR};
	bool DoEval(std::map<std::string, bool> const &var_val,
		std::string const &expr_str, std::vector<ExprNode> const &token) const;

private:
	// location of expr in the str
	std::pair<unsigned int, unsigned int> expr_loc_;
	NodeType op_;
	unsigned int left_, right_;

};

class EvalBoolExpr {
public:
	EvalBoolExpr(std::string const &expr_str);

	// build structure for evaluation
	// returns false if an error occurs
	// this recursive
	// closed interval [expr_begin, expr_end]
	// child has to be pointed to the vector[k]
	// if this is the 1st level of recursion
	// find a pointer and fill in the space
	// side: false - left; true - right
	bool InitBuildEvalStruct(unsigned int expr_begin, unsigned int expr_end, bool side,
		ExprNode &par);

	bool EvalResult(std::map<std::string, bool> const &var_val);

	void InitPrep();

private:
	std::string const *input_str_;
	// stores each level of operation
	std::vector<ExprNode> expr_parse_;

};

#endif  // QM4C_EVAL_BOOL_EXPR_H_

