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

#include "parse_c_bool_expr.h"

ParseCBoolExpr::ExprType ParseCBoolExpr::ProcessExpr(std::string const &input, 
													 std::string &str1, 
													 std::string &str2) {

	// TODO: remove spaces in the expression
	ExprType expr_type = ParseCBoolExpr::EXPR_ERROR;
	
	unsigned int not_count = 0;  // # of ~
	unsigned int left_par = 0;  // # of (
	unsigned int right_par = 0;   // # of )

	// TODO: !!! the following variables are UNINITIALIZED !!!

	// if parentheses need to be removed, that's where they are
	unsigned int first_left_par;  
	unsigned int last_right_par;

	unsigned int op_loc;  // location of the operator

	// TODO: main processing part
	unsigned int input_loc_front = 0;  // 1st non-space character
	unsigned int input_loc_back = input.length();  // last non-space character
	// these can be equal (OK?)

	// clears spaces at the beginning
	while (input[input_loc_front] == ' ' && (input_loc_front < input.length())) {
		++input_loc_front;
	}
	while (input[input_loc_back] == ' ' && input_loc_back >= 0) {
		--input_loc_back;
	}

	// when checking, mind about certain symmetries!!!
	
	/*
	if (input_loc_front == input.length() 
		|| input[input_loc_front] == ')'
		|| input_loc_back == 0
		|| input[input_loc_back] == '('
		|| input_loc_back < input_loc_front) {
		return expr_type;
	}
	*/
	// put all these checks in a function
	if (ParCheckError(input, input_loc_front, input_loc_back)) {
		return expr_type;
	}

	// strips away '('
	while (input[input_loc_front] == '(' ) {  
		// assumes that input[input_loc_back] == ')'
		++input_loc_front;
		--input_loc_back;
		while (input[input_loc_front] == ' ') {
			++input_loc_front;
		}
		while (input[input_loc_back] == ' ') {
			--input_loc_back;
		}
		if (ParCheckError(input, input_loc_front, input_loc_back)) {
			return expr_type;
		}
	}

	if (input[input_loc_front] == '~') {
		++input_loc_front;
		while (input[input_loc_front] == ' ' 
			&& input_loc_front < input.length()) {
			++input_loc_front;
		}
		if (NotCheckError(input, input_loc_front, input_loc_back)) {
			return expr_type;
		}
		// processing the expression after ~
		str1 = input.substr( input_loc_front, 
			input_loc_back - input_loc_front + 1);
		expr_type = EXPR_NOT;
		return expr_type;
	}

	// TODO: process && || nothing

	// TODO: uninitialized!
	unsigned int and_loc;  // 1st location of &&
	unsigned int or_loc;  // 1st location of ||
	
	// any && || found?
	bool found_and = false;
	bool found_or = false;

	if (!found_and && !found_or) {
		if (VarCheckError(input, input_loc_front, input_loc_back)) {
			return expr_type;
		}
		str1 = input.substr( input_loc_front, 
			input_loc_back - input_loc_front + 1);
		expr_type = EXPR_NOTHING;
		return expr_type;
	}

	return expr_type;
}

bool ParseCBoolExpr::ParCheckError(const std::string &input, 
							  unsigned int input_loc_front, 
							  unsigned int input_loc_back) {
	// possible errors
	// TODO: are they complete? (recursively)
	return (input[input_loc_front] == ')'
		|| input[input_loc_back] == '('
		|| input_loc_back < input_loc_front
		|| input_loc_back < 0
		|| input_loc_front == input.length()
		|| (input[input_loc_front] == '(' && input[input_loc_back] != ')')
		|| (input[input_loc_front] != '(' && input[input_loc_back] == ')'));
}

bool ParseCBoolExpr::NotCheckError(const std::string &input, 
								   unsigned int input_loc_front, 
								   unsigned int input_loc_back) {
	// TODO: do i need more?							 
	return (input_loc_back < input_loc_front);
}

bool ParseCBoolExpr::VarCheckError(const std::string &input, 
								   unsigned int input_loc_front, 
								   unsigned int input_loc_back) {
	// TODO: did i miss anything?
	if (!std::isalpha(input[input_loc_front]) 
		|| input[input_loc_front] != '_') {
			return false;
	}
	
	for (unsigned int i = 0; i != input.length(); ++i) {
		if (!std::isalnum(input[i])
			|| input[i] != '_') {
				return false;
		}
	}

	return true;
}
