#include "atm.h"
#include "auth.h"
#include "menu.h"
#include "user_data.h"
#include "utils.h"
#include <iostream>
#include <vector>

namespace atm {
    void runAtm() {
        std::vector<data::User> users;
        data::ensureDataFile();
        if (!data::loadUsers(users)) {
            std::cout << "Unable to load user data.\n";
            return;
        }

        while (true) {
            showMainMenu();
            int choice = getIntegerInput();
            if (choice == 3) {
                std::cout << "Exiting ATM application.\n";
                break;
            }

            int userIndex = -1;
            if (choice == 1) {
                if (loginUser("admin", users, userIndex)) {
                    adminMenu(users, userIndex);
                }
            } else if (choice == 2) {
                if (loginUser("common", users, userIndex)) {
                    commonMenu(users, userIndex);
                }
            } else {
                std::cout << "Invalid selection.\n";
            }

            data::saveUsers(users);
        }
    }
}
