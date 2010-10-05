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

#ifndef QM4C_SIMPLIFY_BOOL_EXPR_H_
#define QM4C_SIMPLIFY_BOOL_EXPR_H_

#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <utility>

#include "eval_bool_expr.h"

class SimplifyBoolExpr {
public:
	SimplifyBoolExpr();

	// returns true if input is legal and output is the simplified expression
	// returns false if input is illegal
	bool MakeSimple(std::string const &input, std::string &output);

private:
	void CreatTruthTable();

	void CleanUp();

	// checks to see if a char is an alphabet or _
	inline bool IsNonNumOK(char c);
	// checks to see if a char is an alphabet or num or _
	inline bool IsCharOK(char c);

	// parentheses error check
	bool ParCheck();
	
	enum VarType {BOOL_1_, BOOL_0_, BOOL_VAR_, BOOL_ERROR_};
	VarType CheckVar(std::string const &var);

	// strips spaces from input, stores results in input_str_
	// checks for the following kind of errors
	//		wrong varible name beginnings
	//		wrong parenthesis
	bool InitCheckInput(std::string const &input);
	std::string input_str_;
	
	// stores varibles' strings and values
	std::map<std::string, bool> expr_var_;

	EvalBoolExpr eval;

	std::map<unsigned int, bool> truth_table_;

};

inline bool SimplifyBoolExpr::IsNonNumOK(char c) {
	return (std::isalpha(c) || (c == '_'));
}

inline bool SimplifyBoolExpr::IsCharOK(char c) {
	return (std::isalnum(c) || (c == '_'));
}

#endif  // QM4C_SIMPLIFY_BOOL_EXPR_H_

