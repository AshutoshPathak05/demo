#include "menu.h"
#include "accounts.h"
#include "auth.h"
#include "user_data.h"
#include "utils.h"
#include <iostream>

namespace atm {
    void showMainMenu() {
        std::cout << "\n=== ATM WORKFLOW MENU ===\n";
        std::cout << "1. Admin login\n";
        std::cout << "2. Common user login\n";
        std::cout << "3. Exit\n";
        std::cout << "Select option: ";
    }

    void adminMenu(std::vector<data::User>& users, int currentIndex) {
        while (true) {
            std::cout << "\n--- Admin Menu ---\n";
            std::cout << "1. View all accounts\n";
            std::cout << "2. Create account\n";
            std::cout << "3. Delete account\n";
            std::cout << "4. Reset account password / balance\n";
            std::cout << "5. Logout\n";
            std::cout << "Choose option: ";
            int option = getIntegerInput();
            switch (option) {
                case 1:
                    listAccounts(users);
                    break;
                case 2:
                    createAccount(users);
                    data::saveUsers(users);
                    break;
                case 3:
                    deleteAccount(users);
                    data::saveUsers(users);
                    break;
                case 4:
                    modifyAccount(users);
                    data::saveUsers(users);
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid option.\n";
                    break;
            }
        }
    }

    void commonMenu(std::vector<data::User>& users, int currentIndex) {
        while (true) {
            std::cout << "\n--- Common User Menu ---\n";
            std::cout << "1. View balance\n";
            std::cout << "2. Deposit funds\n";
            std::cout << "3. Withdraw funds\n";
            std::cout << "4. Change password\n";
            std::cout << "5. Logout\n";
            std::cout << "Choose option: ";
            int option = getIntegerInput();
            switch (option) {
                case 1:
                    std::cout << "Account balance: " << users[currentIndex].balance << "\n";
                    break;
                case 2:
                    deposit(users, currentIndex);
                    data::saveUsers(users);
                    break;
                case 3:
                    withdraw(users, currentIndex);
                    data::saveUsers(users);
                    break;
                case 4:
                    changePassword(users, currentIndex);
                    data::saveUsers(users);
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid option.\n";
                    break;
            }
        }
    }
}
