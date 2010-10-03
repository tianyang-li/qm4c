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

#include "c_bool_expr_eval.h"

class SimplifyBoolExpr {
public:
	// returns true if input is legal and output is the simplified expression
	// returns false if input is illegal
	static bool MakeSimple(std::string const &input, std::string &output);
private:
};

#endif  // QM4C_SIMPLIFY_BOOL_EXPR_H_