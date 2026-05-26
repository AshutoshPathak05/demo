#include "utils.h"
#include <iostream>
#include <limits>

namespace atm {
    void clearLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int getIntegerInput() {
        int value;
        while (!(std::cin >> value)) {
            std::cin.clear();
            clearLine();
            std::cout << "Please enter a valid number: ";
        }
        clearLine();
        return value;
    }

    double getDoubleInput() {
        double value;
        while (!(std::cin >> value)) {
            std::cin.clear();
            clearLine();
            std::cout << "Please enter a valid amount: ";
        }
        clearLine();
        return value;
    }

    void pauseConsole() {
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
}
