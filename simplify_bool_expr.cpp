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

	/*
	// indicates if input_str_[input_pos - 1] == '~'
	bool prev_is_NOT = false;
	*/

	for (unsigned int i = 0; i != input.length(); ++i) {
		if (input[i] != ' ') {
			/*
			if (prev_is_NOT) {
				if (!IsNonNumOK(input[i])) {
					return false;
				}
				prev_is_NOT = false;
			}
			*/

			input_str_.push_back(input[i]);
			++input_pos;

			if (in_var) {
				if (!IsCharOK(input[i])) {
					return false;
				}
				// wrong place
				// i don't have to care about the case where
				// i == input.length() -1
				if (i < input.length() - 1) {
					if (!IsCharOK(input[i + 1])) {
						in_var = false;
						var_pos_.back().second = input_pos - 1;
					}
				}
			}
			else {
				if (input[i] != '&'
					&& input[i] != '|'
					&& input[i] != '~') {
						// at the beginning of a variable name
						// if (!IsNonNumOK(input[i])) {
						if (!IsCharOK(input[i])) {
							return false;
						}
						in_var = true;
						// i have to care about the case where
						// i == input.length() -1
						if (i < input.length() - 1) {
							if (!IsCharOK(input[i + 1])) {
								in_var = false;
							}
						}
						if (i == input.length() - 1) {
							in_var = false;
						}
						var_pos_.push_back(std::make_pair<unsigned int, unsigned int>(input_pos - 1, input.length()));
						if (!in_var) {
							var_pos_.back().second = input_pos - 1;
						}
				}
				else {
					switch (input[i]) {
						case '&':
							/*
							//in_var = false;
							// replaced with a function with more functionality
							MarkVarNameStrEnd(input_pos,in_var);
							*/
							break;
						case '|':
							/*
							//in_var = false;
							// replaced with a function with more functionality
							MarkVarNameStrEnd(input_pos,in_var);
							*/
							break;
						case '~':
							/*
							//in_var = false;
							// replaced with a function with more functionality
							MarkVarNameStrEnd(input_pos,in_var);
							*/
							/*
							prev_is_NOT = true;
							*/
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

	// TODO: only checked for illegal characters, grammar check needed
	return true;
}

