#pragma once

// GLOBAL
void removeSingleAnn(std::vector<std::string>&, std::string);
void removeMultiAnn(std::vector<std::string>&, std::string, std::string);
void removeEmptyLines(std::vector<std::string>&);
void replaceWinNewLines(std::vector<std::string>&);
void removeBlankLines(std::vector<std::string>&);
std::pair<bool,bool> isSpaced(std::vector<std::string>&);
std::tuple<std::vector<int>,int,int> detectIndentation(std::vector<std::string>&);
void replaceIndentation(std::vector<std::string>&,std::vector<int>&,int);
void formatCurlyBrackets(std::vector<std::string>&);

// PYTHON
void pyRemoveAnnatations(std::vector<std::string>&);
void pyFormat(std::vector<std::string>&);

// C
void cRemoveAnnatations(std::vector<std::string>&);
void cFormat(std::vector<std::string>&);

// C++
void cppRemoveAnnatations(std::vector<std::string>&);
void cppFormat(std::vector<std::string>&);