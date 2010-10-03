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

#include "parse_c_bool_expr.h"

ParseCBoolExpr::ExprType ParseCBoolExpr::ProcessExpr(std::string const &input, 
													 std::string &str1, 
													 std::string &str2, 
													 bool &error) {
	error = false;

	// TODO: remove spaces in the expression
	ExprType expr_type;
	
	int not_count = 0;  // # of ~
	int left_par = 0;  // # of (
	int right_par = 0;   // # of )

	// TODO: !!! the following variables are UNINITIALIZED !!!

	// if parentheses need to be removed, that's where they are
	std::string::iterator first_left_par;  
	std::string::iterator last_right_par;

	std::string::iterator op_loc;  // location of the operator

	return expr_type;
}