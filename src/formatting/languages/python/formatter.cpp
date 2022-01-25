#include <iostream>
#include <string>
#include <algorithm>
#include "../../../headers/formatting.hpp"

#define PYTHON_ANNATATION "#"  // Single line comment
#define PYTHON_ML_ANNATATION "\"\"\"" // Multi line comment


void pyRemoveAnnatations(std::vector<std::string> &fileContents) {
	removeSingleAnn(fileContents, PYTHON_ANNATATION);
	removeMultiAnn(fileContents, PYTHON_ML_ANNATATION);
}

void pyFormat(std::vector<std::string> &fileContents) {
	std::cout << "Formatting Python" << std::endl;

	// size_t pos;

	
	// // replace \r\n with \n
	// fileContents.replace(std::remove(fileContents.begin(), fileContents.end(), '\r'), fileContents.end(), "\n");
	// // replace double newline with one newline
	// while ((pos=fileContents.find("\n\n", 0)) != -1) { fileContents.erase(pos, 1); }
	// // remove newlines at the end of the file and at the beginning of the file
	// if (fileContents[fileContents.length() - 1] == '\n') { fileContents.erase(fileContents.length() - 1); }
	// if (fileContents[0] == '\n') { fileContents.erase(0, 1); }
	// // remove multiple spaces after text and before newline
	// // remove blank lines
	// while ((pos=fileContents.find("\n\n", 0)) != -1) { fileContents.erase(pos, 1); }
	// // remove space around operators > < = ! () [] {} , : ? | &
}