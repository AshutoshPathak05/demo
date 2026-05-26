#ifndef USER_DATA_H
#define USER_DATA_H

#include <string>
#include <vector>

namespace data {
    struct User {
        int id;
        std::string name;
        std::string type;
        std::string password;
        double balance;
    };

    extern const std::string USER_DATA_FILE;

    void ensureDataFile();
    bool loadUsers(std::vector<User>& users);
    bool saveUsers(const std::vector<User>& users);
    int findUserIndex(const std::vector<User>& users, int id);
}

#endif // USER_DATA_H
