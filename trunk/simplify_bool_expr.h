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
#include <set>

#include "eval_bool_expr.h"

class SimplifyBoolExpr;

class BoolProdTerm {
	friend class SimplifyBoolExpr;

public:
	BoolProdTerm();
	static bool OkToCombine(BoolProdTerm &p1, BoolProdTerm &p2,
		BoolProdTerm &result);

	// check to see if p1 and p2 represent the same thing
	static bool Same(BoolProdTerm const &p1, BoolProdTerm const &p2);

	int OneCount();
	std::string ExprStr(std::map<std::string, bool> &expr_var);

private:
	// variables
	int var_;

	// which variables are not in use
	std::set<int> removed_var_;

	// if this has been used in each step
	bool used_;

	// prime implicants this one contains
	std::set<int> prime_impl_;


};

class SimplifyBoolExpr {
public:
	SimplifyBoolExpr();

	// returns true if input is legal and output is the simplified expression
	// returns false if input is illegal
	bool MakeSimple(std::string const &input, std::string &output);

private:
	void CreatTruthTable();

	void CleanUp();

	void QM();
	// Eliminate all columns covered by essential primes
	// Find minimum set of rows that cover the remaining columns
	void CoverageTable();

	// remove used variables
	void RemoveUsed();

	void WriteOutput(std::string &output);

	bool CheckProdTermDuplicate(BoolProdTerm const &new_term);

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

	// variable table
	// index in the vector indicates how many 1's are in the term
	std::vector< std::vector< std::vector<BoolProdTerm> > > var_table_;

	std::vector<BoolProdTerm> prod_term_;

	std::vector<BoolProdTerm> final_prod_term_;

};

inline bool SimplifyBoolExpr::IsNonNumOK(char c) {
	return (std::isalpha(c) || (c == '_'));
}

inline bool SimplifyBoolExpr::IsCharOK(char c) {
	return (std::isalnum(c) || (c == '_'));
}

int OneBitCount(int n);


#endif  // QM4C_SIMPLIFY_BOOL_EXPR_H_

