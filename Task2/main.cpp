#include "Menu.h"
#include <iostream>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    Menu menu(str);
    menu.run();

    return 0;
}