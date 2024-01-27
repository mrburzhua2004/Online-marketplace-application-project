#ifndef PROJECT_OOP_CUSTOMERS_DB_H
#define PROJECT_OOP_CUSTOMERS_DB_H

#include <iostream>
#include <vector>
#include <fstream>

#include "database.h"
#include "seller.h"
#include "customer.h"

// Database class for customers
class Customers_DB : public Database {
private:
    vector<Customer> customers;
public:
    int get_size() override {
        return customers.size();
    }

    // Add a new customer to the database
    void add(string username, string email, string password, string address) {
        Customer new_customer(username, email, password, address);
        customers.push_back(new_customer);
    }

    // Find a customer based on a given key and attribute
    Customer* find(string key, short attribute) {
        for (auto& user : customers) {
            if (key == (user.*customer_methods[attribute])()) {
                return &user;
            }
        }
        return nullptr;
    }
};


#endif //PROJECT_OOP_CUSTOMERS_DB_H
