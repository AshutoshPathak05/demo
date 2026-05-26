#ifndef ATM_ACCOUNTS_H
#define ATM_ACCOUNTS_H

#include <vector>
#include "user_data.h"

namespace atm {
    void printUserRecord(const data::User& user);
    void listAccounts(const std::vector<data::User>& users);
    void createAccount(std::vector<data::User>& users);
    void deleteAccount(std::vector<data::User>& users);
    void modifyAccount(std::vector<data::User>& users);
    void deposit(std::vector<data::User>& users, int currentIndex);
    void withdraw(std::vector<data::User>& users, int currentIndex);
    void changePassword(std::vector<data::User>& users, int currentIndex);
}

#endif // ATM_ACCOUNTS_H
