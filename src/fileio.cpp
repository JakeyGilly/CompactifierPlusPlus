#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

bool isFileReal(std::string file) {
    return std::filesystem::exists(file);
}

std::string filetype(std::string file) {
    return std::filesystem::path(file).extension().string();
}

std::string readFile(std::string file) {
    std::ifstream t(file);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int fileSize(std::string file) {
    std::ifstream in(file, std::ifstream::ate | std::ifstream::binary);
    return (int)in.tellg();
}

void writeFile(std::string file, std::string contents) {
    std::ofstream infile(file);
    infile << contents;
    infile.close();
}
