#pragma once

std::string filetype(std::string);
bool isFileReal(std::string);
std::vector<std::string> readFile(std::string);
int fileSize(std::string);
void writeFile(std::string, std::vector<std::string>&);