#ifndef PROJECT_OOP_SELLERS_DB_H
#define PROJECT_OOP_SELLERS_DB_H

#include <iostream>
#include <vector>
#include <fstream>

#include "database.h"
#include "product.h"
#include "seller.h"

// Database class for sellers
class Sellers_DB : public Database {
private:
    vector<Seller> sellers;
public:
    int get_size() override {
        return sellers.size();
    }

    // Add a new seller to the database
    void add(string username, string email, string password) {
        Seller new_seller(username, email, password);
        sellers.push_back(new_seller);
    }

    // Find a seller based on a given key and attribute
    Seller* find(string key, short attribute) {
        for (auto& user : sellers) {
            if (key == (user.*seller_methods[attribute])()) {
                return &user;
            }
        }
        return nullptr;
    }
};

#endif //PROJECT_OOP_SELLERS_DB_H
