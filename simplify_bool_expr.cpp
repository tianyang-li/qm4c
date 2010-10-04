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

#include "simplify_bool_expr.h"

bool SimplifyBoolExpr::MakeSimple(std::string const &input, std::string &output) {
	if (!InitCheckInput(input)) {
		return false;
	}
	return true;
}

bool SimplifyBoolExpr::InitCheckInput(const std::string &input) {
	// for input_str_
	unsigned int input_pos = 0;
	
	// indicates if i in the for loop (copying input into input_str_
	// makes input[i] in a variable name string
	bool in_var = false;

	// indicates if input_str_[input_pos - 1] == '~'
	bool prev_is_NOT = false;

	// beginning and end of each variable name in input
	std::list< std::pair<unsigned int, unsigned int> > input_var_pos;
	for (unsigned int i = 0; i != input.length(); ++i) {
		if (input[i] != ' ') {
			if (prev_is_NOT) {
				if (!IsNonNumOK(input[i])) {
					return false;
				}
				prev_is_NOT = false;
			}

			input_str_[input_pos] = input[i];
			++input_pos;

			if (in_var) {
				if (!IsCharOK(input[i])) {
					return false;
				}
			}
			else {
				if (input[i] != '&'
					&& input[i] != '|'
					&& input[i] != '~') {
						// at the beginning of a variable name
						if (!IsNonNumOK(input[i])) {
							return false;
						}
						in_var = true;
				}
				else {
					switch (input[i]) {
						case '&':
							in_var = false;
							break;
						case '|':
							in_var = false;
							break;
						case '~':
							in_var = false;
							prev_is_NOT = true;
							break;
						default:
							// what is this char? error!
							return false;
							break;
					}
				}
			}

		}
	}

	return true;
}