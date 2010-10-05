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

class EvalBoolExpr {
public:
	EvalBoolExpr(std::map<std::string, bool> const &var_map, std::string const &expr_str);

	// build structure for evaluation
	// returns false if an error occurs
	bool InitBuildEvalStruct();

private:
	// get each variable's value from here
	std::map<std::string, bool> const *expr_var_;
	std::string const *input_str_;

	/*
	// not really a node in the tree, but it's like a tree stored in a vector
	class EvalNode {
		friend class EvalBoolExpr;

	public:

	private:
		EvalNode(std::map<std::string, bool> const &var_val,
			std::string const &expr_str);
		// get evaluation result
		bool DoEval();

		// set location of the expression
		// returns false if error is found
		// it's an interval like this
		// [expr_begin, expr_end]
		bool InitSetExprLoc(unsigned int expr_begin, unsigned int expr_end);

		std::pair<unsigned int, unsigned int> expr_loc_;

		// OP_VAR_ are for a single variable
		// OP_NOT_, OP_PAR_ will only use left_
		// OP_PAR_ is for something like (X)
		// these 5 are listed in order of increasing precedence
		enum NodeType_ {OP_OR_, OP_AND_, OP_NOT_, OP_PAR_, OP_VAR_};

		// this is to be set in SetExprLoc()
		NodeType_ node_op_;

		EvalBoolExpr::EvalNode *left_, *right_;

		std::map<std::string, bool> const *node_expr_var_;
		std::string const *node_input_str_;
	};

	std::vector<EvalNode> expr_tree_;
	*/

};

#endif  // QM4C_EVAL_BOOL_EXPR_H_

