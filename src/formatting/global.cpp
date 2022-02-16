#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "../headers/formatting.hpp"
#include "../headers/config.hpp"

void removeSingleAnn(std::vector<std::string> &fileContents, std::string ann) {
    for (int i = 0; i < fileContents.size(); i++) {
        if (fileContents[i].find(ann) != (int)-1) {
            fileContents[i] = fileContents[i].substr(0, fileContents[i].find(ann));
        }
    }
}
void removeMultiAnn(std::vector<std::string> &fileContents, std::string ann) {
    int pos;
    int pos2;
    for (int i = 0; i < fileContents.size(); i++) {
        if ((pos=fileContents[i].find(ann)) != (int)-1) {
            if ((pos2=fileContents[i].find(ann, pos + ann.length())) != (int)-1) {
                fileContents[i] = fileContents[i].substr(0, pos) + fileContents[i].substr(pos2 + ann.length());
            } else {
                fileContents[i] = fileContents[i].substr(0, pos);
                i++;
                while ((pos=fileContents[i].find(ann)) == (int)-1) {
                    fileContents.erase(fileContents.begin() + i);
                    i++;
                }
                fileContents[i] = fileContents[i].substr(pos + ann.length());
            }
        }
    }
}

void removeEmptyLines(std::vector<std::string> &fileContents) {
    for (int i = 0; i < fileContents.size(); i++) {
		if (fileContents[i].empty()) {
			fileContents.erase(fileContents.begin() + i);
			i--;
		}
	}
}

void replaceWinNewLines(std::vector<std::string> &fileContents) {
    for (int i = 0; i < fileContents.size(); i++) {
		fileContents[i].erase(std::remove(fileContents[i].begin(), fileContents[i].end(), '\r'), fileContents[i].end());
	}
}

void removeBlankLines(std::vector<std::string> &fileContents) {
    bool removeline = true;
	for (int i = 0; i < fileContents.size(); i++) {
		for (int j = 0; j < fileContents[i].length(); j++) if (fileContents[i][j] != ' ' && fileContents[i][j] != '\t') removeline = false;
		if (removeline) {
			fileContents.erase(fileContents.begin() + i);
			i--;
		}
		removeline = true;
	}
}

std::pair<bool,bool> isSpaced(std::vector<std::string> &fileContents) {
    bool isSpaced = false;
	bool error = false;
	for (int i = 0; i < fileContents.size(); i++) {
		if (fileContents[i].find(":") != (int)-1) {
			if (fileContents[i+1][0] == ' ') isSpaced = true;
            else if (fileContents[i+1][0] != '\t') error = true;
		}
	}
    return std::pair<bool, bool>(isSpaced, error);
}

// i know this isnt the prettiest code but it works
// you may improve it if you want
std::tuple<std::vector<int>, int, int> detectIndentation(std::vector<std::string> &fileContents) {
    int spaces;
    std::vector<int> spacesVec;
    int indentation = 0;
    for (int i = 0; i < fileContents.size(); i++) {
        spaces = 0;
        for (int j = 0; j < fileContents[i].length(); j++) {
            if (fileContents[i][j] == ' ') while (fileContents[i][j] == ' ') {
                spaces++;
                j++;
            }
            if (fileContents[i][j] != ' ' && fileContents[i][j] != '\t') break;
        }
        spacesVec.push_back(spaces);
    }
    for (int i = 0; i < spacesVec.size(); i++) {
        if (spacesVec[i] > 0) {
            for (int j = std::stoi(getValue("MAX_INDENT_SPACE")); j > 1; j--) {
                if (spacesVec[i] % j == 0) {
                    indentation = j;
                    break;
                }
            }
            break;
        }
    }
    for (int i = 0; i < spacesVec.size(); i++) if (spacesVec[i] % indentation != 0) {return std::tuple<std::vector<int>, int, int>(spacesVec, indentation, 1);}
    return std::tuple<std::vector<int>, int, int>(spacesVec, indentation, 0);
}

void replaceIndentation(std::vector<std::string> &fileContents, std::vector<int> &spacesVec, int indentation) {
    for (int i = 0; i < fileContents.size(); i++) {
        for (int j = spacesVec[i] / indentation; j > 0; j--) {
            fileContents[i].replace((indentation * j)-indentation, indentation, "\t");
        }
    }
}
