#ifndef ATM_AUTH_H
#define ATM_AUTH_H

#include <string>
#include <vector>
#include "user_data.h"

namespace atm {
    bool loginUser(const std::string& expectedType, const std::vector<data::User>& users, int& foundIndex);
}

#endif // ATM_AUTH_H
