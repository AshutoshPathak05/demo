#include "accounts.h"
#include "utils.h"
#include <iostream>

namespace atm {
    void printUserRecord(const data::User& user) {
        std::cout << "ID: " << user.id
                  << " | Name: " << user.name
                  << " | Type: " << user.type
                  << " | Balance: " << user.balance << "\n";
    }

    void listAccounts(const std::vector<data::User>& users) {
        if (users.empty()) {
            std::cout << "No accounts are available.\n";
            return;
        }
        for (const auto& user : users) {
            printUserRecord(user);
        }
    }

    void createAccount(std::vector<data::User>& users) {
        std::cout << "Enter new user ID: ";
        int id = getIntegerInput();
        if (data::findUserIndex(users, id) >= 0) {
            std::cout << "This ID is already in use.\n";
            return;
        }

        std::cout << "Enter name: ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Enter password: ";
        std::string password;
        std::getline(std::cin, password);

        std::cout << "Enter type (common/admin): ";
        std::string type;
        std::getline(std::cin, type);
        if (type != "common" && type != "admin") {
            std::cout << "Invalid user type. Use 'common' or 'admin'.\n";
            return;
        }

        std::cout << "Enter initial balance: ";
        double balance = getDoubleInput();

        users.push_back({id, name, type, password, balance});
        std::cout << "Account created successfully.\n";
    }

    void deleteAccount(std::vector<data::User>& users) {
        std::cout << "Enter account ID to delete: ";
        int id = getIntegerInput();
        int index = data::findUserIndex(users, id);
        if (index < 0) {
            std::cout << "Account not found.\n";
            return;
        }
        users.erase(users.begin() + index);
        std::cout << "Account deleted successfully.\n";
    }

    void modifyAccount(std::vector<data::User>& users) {
        std::cout << "Enter account ID to modify: ";
        int id = getIntegerInput();
        int index = data::findUserIndex(users, id);
        if (index < 0) {
            std::cout << "Account not found.\n";
            return;
        }

        data::User& user = users[index];
        std::cout << "Current user record:\n";
        printUserRecord(user);

        std::cout << "Enter new password (leave blank to keep): ";
        std::string password;
        std::getline(std::cin, password);
        if (!password.empty()) {
            user.password = password;
        }

        std::cout << "Enter new balance (-1 to keep current): ";
        double balance = getDoubleInput();
        if (balance >= 0) {
            user.balance = balance;
        }

        std::cout << "Account updated successfully.\n";
    }

    void deposit(std::vector<data::User>& users, int currentIndex) {
        std::cout << "Enter deposit amount: ";
        double amount = getDoubleInput();
        if (amount <= 0) {
            std::cout << "Amount must be greater than zero.\n";
            return;
        }
        users[currentIndex].balance += amount;
        std::cout << "Deposit successful. New balance: " << users[currentIndex].balance << "\n";
    }

    void withdraw(std::vector<data::User>& users, int currentIndex) {
        std::cout << "Enter withdrawal amount: ";
        double amount = getDoubleInput();
        if (amount <= 0) {
            std::cout << "Amount must be greater than zero.\n";
            return;
        }
        if (amount > users[currentIndex].balance) {
            std::cout << "Insufficient funds.\n";
            return;
        }
        users[currentIndex].balance -= amount;
        std::cout << "Withdrawal successful. New balance: " << users[currentIndex].balance << "\n";
    }

    void changePassword(std::vector<data::User>& users, int currentIndex) {
        std::cout << "Enter current password: ";
        std::string current;
        std::getline(std::cin, current);
        if (users[currentIndex].password != current) {
            std::cout << "Current password does not match.\n";
            return;
        }
        std::cout << "Enter new password: ";
        std::string next;
        std::getline(std::cin, next);
        if (next.empty()) {
            std::cout << "Password cannot be empty.\n";
            return;
        }
        users[currentIndex].password = next;
        std::cout << "Password changed successfully.\n";
    }
}
