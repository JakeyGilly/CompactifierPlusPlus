#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include "../../../headers/formatting.hpp"
#include "../../../headers/config.hpp"

#define PYTHON_ANNATATION "#"  // Single line comment
#define PYTHON_ML_ANNATATION "\"\"\"" // Multi line comment


void pyRemoveAnnatations(std::vector<std::string> &fileContents) {
	removeSingleAnn(fileContents, PYTHON_ANNATATION);
	removeMultiAnn(fileContents, PYTHON_ML_ANNATATION);
}

void pyFormat(std::vector<std::string> &fileContents) {
	std::cout << "Formatting Python" << std::endl;
	replaceWinNewLines(fileContents);
	removeEmptyLines(fileContents);
	removeBlankLines(fileContents);
	std::pair<bool, bool> space = isSpaced(fileContents);
	if (std::get<1>(space)) return; // if indent error
	if (std::get<0>(space)) { // if spaced
		std::tuple<std::vector<int>,int,int> indent = detectIndentation(fileContents); // spacevec, indent
		if (std::get<2>(indent) == -1) return; // if indent error
		replaceIndentation(fileContents, std::get<0>(indent), std::get<1>(indent));
	}
	// check each module succeeds
	// remove multiple spaces after text and before newline
	// remove space around operators > < = ! () [] {} , : ? | &
}