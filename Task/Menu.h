#ifndef MENU_H
#define MENU_H

#include "StringAnalyzer.h"

class Menu {
private:
    StringAnalyzer analyzer;

public:
    Menu(const std::string& str);
    void run();
};

#endif