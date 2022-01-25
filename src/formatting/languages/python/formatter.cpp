#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "../../../headers/formatting.hpp"

#define PYTHON_ANNATATION "#"  // Single line comment
#define PYTHON_ML_ANNATATION "\"\"\"" // Multi line comment


void pyRemoveAnnatations(std::vector<std::string> &fileContents) {
	removeSingleAnn(fileContents, PYTHON_ANNATATION);
	removeMultiAnn(fileContents, PYTHON_ML_ANNATATION);
}

void pyFormat(std::vector<std::string> &fileContents) {
	std::cout << "Formatting Python" << std::endl;
	// replace \r\n with \n
	for (int i = 0; i < fileContents.size(); i++) {
		fileContents[i].erase(std::remove(fileContents[i].begin(), fileContents[i].end(), '\r'), fileContents[i].end());
	}
	// remove empty lines
	for (int i = 0; i < fileContents.size(); i++) {
		if (fileContents[i].empty()) {
			fileContents.erase(fileContents.begin() + i);
			i--;
		}
	}
	// remove newlines at the end of the file and at the beginning of the file
	if (fileContents.size() > 0) {
		if (fileContents[0].empty()) {
			fileContents.erase(fileContents.begin());
		}
		if (fileContents[fileContents.size() - 1].empty()) {
			fileContents.erase(fileContents.end() - 1);
		}
	}
	bool removeline = true;
	for (int i = 0; i < fileContents.size(); i++) {
		for (int j = 0; j < fileContents[i].length(); j++) {
			if (fileContents[i][j] != ' ' && fileContents[i][j] != '\t') {
				removeline = false;
			} 
		}
		if (removeline) {
			fileContents.erase(fileContents.begin() + i);
			i--;
		}
		removeline = true;
	}
	// // remove multiple spaces after text and before newline
	// // remove blank lines
	// while ((pos=fileContents.find("\n\n", 0)) != -1) { fileContents.erase(pos, 1); }
	// // remove space around operators > < = ! () [] {} , : ? | &
}