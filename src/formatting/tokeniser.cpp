#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenise(std::string_view input) {
    std::vector<std::string> tokens;
    std::string token;
    for (auto c : input) {  
        if (c == ' ' || c == '\n' || c == '\t') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else token += c;
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}