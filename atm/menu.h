#ifndef ATM_MENU_H
#define ATM_MENU_H

#include <vector>
#include "user_data.h"

namespace atm {
    void showMainMenu();
    void adminMenu(std::vector<data::User>& users, int currentIndex);
    void commonMenu(std::vector<data::User>& users, int currentIndex);
}

#endif // ATM_MENU_H
