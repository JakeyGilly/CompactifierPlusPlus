#include <iostream>
#include <string>
#include <algorithm>
#include "../../../headers/formatting.hpp"

#define PYTHON_ANNATATION "#"  // Single line comment
#define PYTHON_ML_ANNATATION "\"\"\"" // Multi line comment

std::string pyRemoveAnnatations(std::string fileContents) {
	fileContents = removeSingleAnn(fileContents, PYTHON_ANNATATION);
	fileContents = removeMultiAnn(fileContents, PYTHON_ML_ANNATATION);
	return fileContents;
}

std::string pyFormat(std::string fileContents) {
	size_t pos;
	fileContents.erase(std::remove(fileContents.begin(), fileContents.end(), '\t'), fileContents.end());
	fileContents.replace(std::remove(fileContents.begin(), fileContents.end(), '\r'), fileContents.end(), "\n");
	while ((pos=fileContents.find("\n\n", 0)) != -1) { fileContents.erase(pos, 1); }
	if (fileContents[fileContents.length() - 1] == '\n') { fileContents.erase(fileContents.length() - 1); }
	if (fileContents[0] == '\n') { fileContents.erase(0, 1); }
	return fileContents;
}