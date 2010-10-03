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

#ifndef QM4C_PARCE_C_BOOL_EXPR_H_
#define QM4C_PARCE_C_BOOL_EXPR_H_

#include <string>

class ParseCBoolExpr {
public:
	// get the type of operation this expression does
	enum ExprType {EXPR_AND, EXPR_OUT, EXPR_NOT, EXPR_NOTHING};
	// takes input and processes it
	// returns the type of operation this expression performs
	// it strips as many spaces, ('s, and )'s as possible
	// for binary operations, str1 str2 stores each operand's expression
	// for unary operation (~) only str1 is used
	// error indicates if there's any error detected in the expression
	static ExprType ProcessExpr(std::string const &input, 
		std::string &str1, std::string &str2, bool &error);

private:
};

#endif  // QM4C_PARCE_C_BOOL_EXPR_H_