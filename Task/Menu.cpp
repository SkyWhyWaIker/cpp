#include "Menu.h"
#include <iostream>

Menu::Menu(const std::string& str) : analyzer(str) {}

void Menu::run() {
    int choice;
    do {
        std::cout << "1. Add delimiter\n";
        std::cout << "2. Remove delimiters\n";
        std::cout << "3. Get next token\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char delimiter;
                std::cout << "Enter delimiter: ";
                std::cin >> delimiter;
                analyzer.addDelimiter(delimiter);
                break;
            }
            case 2:
                analyzer.removeDelimiters();
                break;
            case 3:
                std::cout << "Next token: " << analyzer.getNextToken() << "\n";
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}