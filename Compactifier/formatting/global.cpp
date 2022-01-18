#include <string>
#include <iostream>
#include "../headers/formatting.hpp"

std::string removeSingleAnn(std::string fileContents, std::string ann) {
    size_t pos;
    int newline;
    while ((pos = fileContents.find(ann, 0)) != -1) {
        newline = fileContents.find("\n", pos);
        if (newline == -1) {
            fileContents.erase(pos, fileContents.length() - pos);
        } else {
            fileContents.erase(pos, newline - pos);
        }
    }
    return fileContents;
}
std::string removeMultiAnn(std::string fileContents, std::string ann) {
    size_t pos;
    int end;
    while ((pos = fileContents.find(ann, 0)) != -1) {
        end = fileContents.find(ann, pos + ann.length());
        if (end == -1) {
            fileContents.erase(pos, fileContents.length() - pos);
        } else {
            fileContents.erase(pos, end - pos + ann.length());
        }
    }
    return fileContents;
}
