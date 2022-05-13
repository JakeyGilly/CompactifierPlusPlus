#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include "../../../headers/formatting.hpp"
#include "../../../headers/config.hpp"

#define C_ANNATATION "//"  // Single line comment
#define C_ML_ANNATATION "/*" // Multi line comment
#define C_ML_ANNATATION_END "*/" // Multi line comment


void cRemoveAnnatations(std::vector<std::string> &fileContents) {
	removeSingleAnn(fileContents, C_ANNATATION);
	removeMultiAnn(fileContents, C_ML_ANNATATION, C_ML_ANNATATION_END);
}

void cFormat(std::vector<std::string> &fileContents) {
	std::cout << "Formatting C" << std::endl;
	replaceWinNewLines(fileContents);
	formatCurlyBrackets(fileContents);
	removeEmptyLines(fileContents);
	removeBlankLines(fileContents);
	std::pair<bool, bool> space = isSpaced(fileContents);
	if (std::get<1>(space)) return; // if indent error
	if (std::get<0>(space)) { // if spaced
		std::tuple<std::vector<int>,int,int> indent = detectIndentation(fileContents); // spacevec, indent
		if (std::get<2>(indent) == -1) return; // if indent error
		replaceIndentation(fileContents, std::get<0>(indent), std::get<1>(indent));
	}
	// remove multiple spaces after text and before newline
	// remove space around operators > < = ! () [] {} , : ? | &
}