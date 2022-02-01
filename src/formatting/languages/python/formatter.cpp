#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
	if (std::get<1>(isSpaced(fileContents))) return; // if indent error
	if (std::get<0>(isSpaced(fileContents))) { // if spaced
		int spaces;
		std::vector<int> spacesVec;
		int indentation = 0;
		std::cout << "Detected spaced indentation" << std::endl;
		for (size_t i = 0; i < fileContents.size(); i++) {
			spaces = 0;
			for (size_t j = 0; j < fileContents[i].length(); j++) {
				if (fileContents[i][j] == ' ') while (fileContents[i][j] == ' ') {
					spaces++;
					j++;
				}
				if (fileContents[i][j] != ' ' && fileContents[i][j] != '\t') break;
			}
			spacesVec.push_back(spaces);
		}
		for (size_t i = 0; i < spacesVec.size(); i++) {
			if (spacesVec[i] > 0) {
				for (int j = stoi(getValue("MAX_INDENT_SPACE")); j > 1; j--) {
					if (spacesVec[i] % j == 0) {
						indentation = j;
						break;
					}
				}
				break;
			}
		}
		std::cout << "We detected your indentation as " << indentation << " spaces" << std::endl;
		std::cout << "Is this correct? (y/n): ";
		std::string input;
		std::cin >> input;
		if (input == "n") {
			std::cout << "Please enter the correct indentation" << std::endl;
			std::cin >> indentation;
		}
		// check manually because i dont trust the user
		for (size_t i = 0; i < spacesVec.size(); i++) {
			if (spacesVec[i] % indentation != 0) {
				std::cout << "Indentation error" << std::endl;
				return;
			}
		}
		for (size_t i = 0; i < fileContents.size(); i++) {
			for (int j = spacesVec[i] / indentation; j > 0; j--) {
				fileContents[i].replace((indentation * j)-indentation, indentation, "\t");
			}
		}
	}

	// replace spaces with tabs
	// check each module succeeds
	// remove multiple spaces after text and before newline
	// remove blank lines
	// while ((pos=fileContents.find("\n\n", 0)) != -1) { fileContents.erase(pos, 1); }
	// remove space around operators > < = ! () [] {} , : ? | &
}