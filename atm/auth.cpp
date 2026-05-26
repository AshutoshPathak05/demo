#include "auth.h"
#include "utils.h"
#include <iostream>

namespace atm {
    bool loginUser(const std::string& expectedType, const std::vector<data::User>& users, int& foundIndex) {
        std::cout << "Enter user ID: ";
        int id = getIntegerInput();
        std::cout << "Enter password: ";
        std::string password;
        std::getline(std::cin, password);

        int index = data::findUserIndex(users, id);
        if (index < 0) {
            std::cout << "User not found.\n";
            return false;
        }

        const data::User& user = users[index];
        if (user.password != password) {
            std::cout << "Incorrect password.\n";
            return false;
        }
        if (user.type != expectedType) {
            std::cout << "User type does not match login type.\n";
            return false;
        }

        foundIndex = index;
        return true;
    }
}
