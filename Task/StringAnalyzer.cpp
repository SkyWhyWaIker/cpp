#include "StringAnalyzer.h"
#include <sstream>
#include <algorithm>

StringAnalyzer::StringAnalyzer(const std::string& str) : str(str), currentToken(0) {
    // Разделение строки на токены
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
}

void StringAnalyzer::addDelimiter(char delimiter) {
    delimiters.push_back(delimiter);
    // Переразбиваем строку на токены с учетом нового разделителя
    tokens.clear();
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
}

void StringAnalyzer::removeDelimiters() {
    str.erase(std::remove_if(str.begin(), str.end(), [this](char c) {
        return std::find(delimiters.begin(), delimiters.end(), c) != delimiters.end();
    }), str.end());
}

std::string StringAnalyzer::getNextToken() {
    if (currentToken < tokens.size()) {
        return tokens[currentToken++];
    }
    return "";
}

bool StringAnalyzer::isEndOfAnalysis() {
    return currentToken >= tokens.size();
}