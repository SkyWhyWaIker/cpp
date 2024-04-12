#ifndef STRINGANALYZER_H
#define STRINGANALYZER_H

#include <string>
#include <vector>

class StringAnalyzer {
private:
    std::string str;
    std::vector<char> delimiters;
    std::vector<std::string> tokens;
    size_t currentToken;

public:
    StringAnalyzer(const std::string& str);
    void addDelimiter(char delimiter);
    void removeDelimiters();
    std::string getNextToken();
    bool isEndOfAnalysis();
};

#endif // STRINGANALYZER_H