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
void removeMultiAnn(std::vector<std::string> &fileContents, std::string ann, std::string annEnd) {
    for (int i = 0; i < fileContents.size(); i++) {
        int pos, pos2;
        if ((pos=fileContents[i].find(ann)) != (int)-1) {
            if ((pos2=fileContents[i].find(annEnd, pos+1)) != (int)-1) {
                fileContents[i] = fileContents[i].substr(0, pos) + fileContents[i].substr(pos2+annEnd.size());
            } else {
                fileContents[i] = fileContents[i].substr(0, pos);
                // find pos2 on next line
                for (int j = i+1; j < fileContents.size(); j++) {
                    if ((pos2=fileContents[j].find(annEnd)) != (int)-1) {
                        fileContents[j] = fileContents[j].substr(pos2+annEnd.size());
                    } else {
                        // shift all lines down
                        for (int k = j; k < fileContents.size(); k++) {
                            fileContents[k] = fileContents[k+1];
                        }
                        fileContents.pop_back();
                        break;
                    }
                }
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

void formatCurlyBrackets(std::vector<std::string> &fileContents) {
    int pos, pos2;
    int i1, i2;
    bool foundend = false;
    for (int i = 0; i < fileContents.size(); i++) {
        int x = i;
        if ((pos=fileContents[i].find("{")) != (int)-1) {
            i1 = i;
            while (fileContents[i][pos-1] == ' ' || fileContents[i][pos-1] == '\t') {
                fileContents[i].erase(pos-1, 1);
                pos--;
            }
            if (fileContents[i] == "{") {
                for (int j = i; j < fileContents.size(); j++) {
                    fileContents[j] = fileContents[j+1];
                }
                fileContents[i-1].append("{");
                i1--;
            }
            while (true) {
                if ((pos2=fileContents[i].find("}")) != (int)-1) {
                    i2 = i;
                    break;
                } else {
                    i++;
                }
            }
            while (fileContents[i][pos2-1] == ' ' || fileContents[i][pos2-1] == '\t') {
                fileContents[i].erase(pos2-1, 1);
                pos2--;
            }
            std::string statementcode;
            for (int j = i1+1; j < i2; j++) {
                statementcode.append(fileContents[j]);
                statementcode.append("\n");
            }
            bool erase = true;
            for (int j = 0; j < statementcode.length(); j++) {
                std::cout << statementcode[j];
                if (statementcode[j] != ' ' && statementcode[j] != '\t' && statementcode[j] != '\n') erase = false;
            }
            std::cout << "erase: " << erase << std::endl;
            if (erase) {
                fileContents.erase(fileContents.begin()+i1, fileContents.begin()+i2+1);
            }
        }
        i = x;
        // TODO:
        // manage statements
        // statements without curly brackets if one line in manage statements
    }
}

