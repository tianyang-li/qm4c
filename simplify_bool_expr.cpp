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

SimplifyBoolExpr::SimplifyBoolExpr()
: eval(input_str_) {
}

bool SimplifyBoolExpr::MakeSimple(std::string const &input, std::string &output) {
	eval.InitPrep();
	CleanUp();

	if (!InitCheckInput(input)) {
		return false;
	}

	CreatTruthTable();

	// TODO: processing

	void QM();

	return true;
}

bool SimplifyBoolExpr::InitCheckInput(const std::string &input) {
	// add these first
	expr_var_["1"] = true;
	expr_var_["0"] = false;

	// for input_str_
	unsigned int input_pos = 0;
	
	// indicates if i in the for loop (copying input into input_str_
	// makes input[i] in a variable name string
	bool in_var = false;

	// stores the beginning and end of each variable name string
	// in input_str_
	// for each variable (beginning, end) indicates postions in input_str_
	std::vector< std::pair<unsigned int, unsigned int> > var_pos_;

	for (unsigned int i = 0; i != input.length(); ++i) {
		if (input[i] != ' ') {

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
				if (i == input.length() - 1) {
					var_pos_.back().second = input_pos - 1;
				}
			}
			else {
				if (input[i] != '&'
					&& input[i] != '|'
					&& input[i] != '!'
					&& input[i] != '('
					&& input[i] != ')') {
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
							break;
						case '|':
							break;
						case '!':
							break;
						case '(':
							break;
						case ')':
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

	// XXX: only checked for illegal characters, grammar check needed

	// stores where non-0 constants are, replace them with 1 later
	std::vector< std::pair<unsigned int, unsigned int> > pos_1;

	for (unsigned int i = 0; i != var_pos_.size(); ++i) {

		switch (CheckVar(input_str_.substr(var_pos_[i].first, var_pos_[i].second - var_pos_[i].first + 1))) {
			case BOOL_0_:
				break;
			case BOOL_1_:
				pos_1.push_back(var_pos_[i]);
				break;
			case BOOL_VAR_:
				// set all values of variables to false (OK?)
				expr_var_[input_str_.substr(var_pos_[i].first, 
					var_pos_[i].second - var_pos_[i].first + 1)] = false;
				break;
			case BOOL_ERROR_:
				return false;
				break;
 		}
	}

	// non-0 constants replaced with 1 
	// go backward so when positions in behind get changed, ones in front
	// won't get changed
	for (unsigned int i = 0; i != pos_1.size(); ++i) {
		input_str_.replace(pos_1[pos_1.size() - 1 - i].first, 
			pos_1[pos_1.size() - 1 - i].second - pos_1[pos_1.size() - 1 - i].first + 1, "1");
	}

	if (input_str_.length() == 0 ) {
		return false;
	}

	if (!ParCheck()) {
		return false;
	}

	// it's useless, see comments InitBuildEvalStruct()
	ExprNode useless_expr_node;
	if (!eval.InitBuildEvalStruct(0, input_str_.length() - 1, false, useless_expr_node)) {
		return false;
	}

	return true; 
}

SimplifyBoolExpr::VarType SimplifyBoolExpr::CheckVar(const std::string &var) {
	// "0"
	if (var == "0") return BOOL_0_;

	// non-0 numerical constant
	if (std::isdigit(var[0])) {
		for (unsigned int i = 1; i < var.length(); ++i) {
			if (!std::isdigit(var[i])) {
				return BOOL_ERROR_;
			}
		}
		return BOOL_1_;
	}

	// a variable
	for (unsigned int i = 0; i != var.length(); ++i) {
		if (!IsCharOK(var[i])) {
			return BOOL_ERROR_;
		}
	}
	return BOOL_VAR_;
}

bool SimplifyBoolExpr::ParCheck() {
	// it's like a stack for parentheses
	// use signed version to prevent unnecessary errors
	int par_stack = 0;
	for (unsigned int i = 0; i != input_str_.length(); ++i) {
		switch (input_str_[i]) {
			case '(':
				++par_stack;
				break;
			case ')':
				--par_stack;
				break;
			default:
				break;
		}
	}
	return !par_stack;
}

void SimplifyBoolExpr::CreatTruthTable() {
	// get as much as i need XXX: maybe don't don this in the future
	var_table_.resize(expr_var_.size() - 2);
	var_table_.front().resize(expr_var_.size() - 2);

	unsigned int range = 1 << (expr_var_.size() - 2);
	unsigned int var_index;
	std::map<std::string, bool>::iterator var_it;
	for (unsigned int i = 0; i != range; ++i) {
		var_index = 0;
		for (var_it = expr_var_.begin(); var_it != expr_var_.end(); ++var_it) {
			if (var_it->first != "0"
				&& var_it->first != "1") {
					var_it->second = (((1 << var_index) & i) != 0);
					++var_index;
			}
		}
		// only i's whose function value is true is needed
		if (eval.EvalResult(expr_var_)) {
			BoolProdTerm temp_prod;
			temp_prod.var_ = i;
			var_table_.front()[temp_prod.OneCount()].push_back(temp_prod);
		}
	}
}

void SimplifyBoolExpr::CleanUp() {
	expr_var_.clear();
	var_table_.clear();
}

void SimplifyBoolExpr::QM() {
	// core of QM implementation
	for (int i = 0; i < expr_var_.size(); ++i) {
		for (int j = 0; j < expr_var_.size() - i -1; ++j)
	}
}

bool BoolProdTerm::OkToCombine(const BoolProdTerm &p1, 
							   const BoolProdTerm &p2, 
							   BoolProdTerm &result) {
	// boolean OR
	unsigned int diff_count = 0;

	unsigned int diff_loc;

	for (unsigned int i = 0; i != 8 * sizeof(unsigned int); ++i) {
		if ((p1.var_ & (1 << i)) != (p2.var_ & (1 << i))) {
			if (p1.removed_var_.find(i) == p1.removed_var_.end()
				&& p2.removed_var_.find(i) == p2.removed_var_.end()) {
					++diff_count;
					diff_loc = i;
			}
		}
	}

	if (diff_count > 1) return false;

	result.var_ = p1.var_;
	result.removed_var_ = p1.removed_var_;
	if (diff_count == 1) {
		result.removed_var_.insert(diff_loc);
	}

	return true;
}

unsigned int BoolProdTerm::OneCount() {
	unsigned int one_count = 0;
	for (unsigned int i = 0; i != 8 * sizeof(var_); ++i) {
		if ((var_ & (1 << i)) != 0) {
			++one_count;
		}
	}
	return one_count;
}
