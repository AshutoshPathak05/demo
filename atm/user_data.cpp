#include "user_data.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace data {
    const std::string USER_DATA_FILE = "atm_users.txt";

    static void writeSampleData() {
        std::vector<User> initial = {
            {1000, "Admin User", "admin", "admin123", 0.0},
            {1001, "Common User", "common", "user123", 500.0}
        };
        saveUsers(initial);
    }

    void ensureDataFile() {
        std::ifstream infile(USER_DATA_FILE);
        if (!infile.good()) {
            writeSampleData();
        }
    }

    bool loadUsers(std::vector<User>& users) {
        users.clear();
        std::ifstream infile(USER_DATA_FILE);
        if (!infile.is_open()) {
            return false;
        }

        std::string line;
        while (std::getline(infile, line)) {
            if (line.empty()) continue;
            std::istringstream parts(line);
            std::string token;
            User item;
            if (!std::getline(parts, token, '|')) continue;
            item.id = std::stoi(token);
            if (!std::getline(parts, item.name, '|')) continue;
            if (!std::getline(parts, item.type, '|')) continue;
            if (!std::getline(parts, item.password, '|')) continue;
            if (!std::getline(parts, token, '|')) continue;
            item.balance = std::stod(token);
            users.push_back(item);
        }
        return true;
    }

    bool saveUsers(const std::vector<User>& users) {
        std::ofstream outfile(USER_DATA_FILE, std::ios::trunc);
        if (!outfile.is_open()) {
            return false;
        }

        for (const User& item : users) {
            outfile << item.id << "|"
                    << item.name << "|"
                    << item.type << "|"
                    << item.password << "|"
                    << item.balance << "\n";
        }
        return true;
    }

    int findUserIndex(const std::vector<User>& users, int id) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].id == id) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
}
