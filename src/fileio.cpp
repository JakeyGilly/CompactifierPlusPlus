#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

bool isFileReal(std::string file) {
    return std::filesystem::exists(file);
}

std::string filetype(std::string file) {
    return std::filesystem::path(file).extension().string();
}

std::vector<std::string> readFile(std::string file) {
    std::ifstream in(file);
    if (!in) {
        return std::vector<std::string>();
    }
    std::string str;
    std::vector<std::string> fileContents;
    while (std::getline(in, str)) {
        fileContents.push_back(str);
    }
    in.close();
    return fileContents;
}

int fileSize(std::string file) {
    std::ifstream in(file, std::ifstream::ate | std::ifstream::binary);
    return (int)in.tellg();
}

void writeFile(std::string file, std::vector<std::string>& contents) {
    std::ofstream in(file);
    for (int i = 0; i < contents.size(); i++) {
        in << contents[i] << std::endl;
    }
    in.close();
}
