#include <string>
#include <iostream>
#include <vector>
#include "../headers/formatting.hpp"

void removeSingleAnn(std::vector<std::string> &fileContents, std::string ann) {
    for (int i = 0; i < fileContents.size(); i++) {
        if (fileContents[i].find(ann) != -1) {
            fileContents[i] = fileContents[i].substr(0, fileContents[i].find(ann));
        }
    }
}
void removeMultiAnn(std::vector<std::string> &fileContents, std::string ann) {
    size_t pos;
    size_t pos2;
    for (int i = 0; i < fileContents.size(); i++) {
        if ((pos=fileContents[i].find(ann)) != -1) {
            if ((pos2=fileContents[i].find(ann, pos + ann.length())) != -1) {
                fileContents[i] = fileContents[i].substr(0, pos) + fileContents[i].substr(pos2 + ann.length());
            } else {
                fileContents[i] = fileContents[i].substr(0, pos);
                i++;
                while ((pos=fileContents[i].find(ann)) == -1) {
                    fileContents.erase(fileContents.begin() + i);
                    i++;
                }
                fileContents[i] = fileContents[i].substr(pos + ann.length());
            }
        }
    }
}
