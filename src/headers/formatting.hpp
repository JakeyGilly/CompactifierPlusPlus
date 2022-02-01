#pragma once

// GLOBAL
void removeSingleAnn(std::vector<std::string>&, std::string);
void removeMultiAnn(std::vector<std::string>&, std::string);
void removeEmptyLines(std::vector<std::string>&);
void replaceWinNewLines(std::vector<std::string>&);
void removeBlankLines(std::vector<std::string>&);
std::pair<bool,bool> isSpaced(std::vector<std::string>&);
std::tuple<std::vector<int>,int,int> detectIndentation(std::vector<std::string>&);
void replaceIndentation(std::vector<std::string>&,std::vector<int>&,int);

// PYTHON
void pyRemoveAnnatations(std::vector<std::string>&);
void pyFormat(std::vector<std::string>&);