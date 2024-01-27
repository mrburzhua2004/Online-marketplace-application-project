#ifndef PROJECT_OOP_CUSTOMER_H
#define PROJECT_OOP_CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "user.h"

// Derived class representing a customer, inheriting from User
class Customer : public User {
private:
    string address;
public:
    // Constructor for initializing customer data
    Customer(string& username, string& email, string& password, string& address) :
            User(username, email, password), address(address) {}

    // Override the display_info function to provide customer-specific information
    void display_info() override {
        cout << "\nName: " << username << "\nEmail: " << email << "\nAddress: " << address << endl;
    }
};

#endif //PROJECT_OOP_CUSTOMER_H
