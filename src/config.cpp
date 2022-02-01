#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "headers/fileio.hpp"

#define CONFIG_FILE "config.cfg"

std::vector<std::pair<std::string, std::string>> pharseConfig() {
    std::vector<std::string> fileContents = readFile(CONFIG_FILE);
    std::vector<std::pair<std::string, std::string>> config;
    for (int i = 0; i < fileContents.size(); i++) {
        if (fileContents[i][0] == '#') continue; // comments
        if (fileContents[i][0] == '\n') continue; // empty lines
        if (fileContents[i][0] == '\r') continue; // empty lines
        if (fileContents[i].find("=") == std::string::npos) continue; // no =
        fileContents[i].erase(std::remove(fileContents[i].begin(), fileContents[i].end(), ' '), fileContents[i].end());
        std::string key = fileContents[i].substr(0, fileContents[i].find("="));
        std::string value = fileContents[i].substr(fileContents[i].find("=") + 1);
        config.push_back(std::make_pair(key, value));
    }
    std::cout << "Config file loaded" << std::endl;
    // print keys loaded
    std::string keys;
    for (int i = 0; i < config.size(); i++) {
        keys += config[i].first + ", ";
    }
    std::cout << "Loaded Keys: " << keys << std::endl;
    return config;
}

bool checkKey(std::string key) {
    std::vector<std::pair<std::string, std::string>> config = pharseConfig();
    for (int i = 0; i < config.size(); i++) {
        if (config[i].first == key) return true;
    }
    return false;
}

std::string getValue(std::string key) {
    std::vector<std::pair<std::string, std::string>> config = pharseConfig();
    for (int i = 0; i < config.size(); i++) {
        if (config[i].first == key) return config[i].second;
    }
    return "";
}

