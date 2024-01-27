#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class representing a user
class User {
protected:
    string username;
    string email;
    string password;
    double balance;

    // Virtual function to be overridden by derived classes
    virtual void display_info() {};
public:
    // Constructor for initializing user data
    User(string& username, string& email, string& password) :
            username(username), email(email), password(password) {
        balance = 0;
    }

    // Getter functions for accessing private member variables
    string get_username() {
        return username;
    }

    string get_email() {
        return email;
    }

    string get_password() {
        return password;
    }

    // Display the user's balance
    void show_balance() const {
        cout << "Balance: " << balance << "$";
    }

    // Update user's balance and return success status
    bool update_balance(double diff) {
        if (balance + diff < 0) {
            return false;
        }
        else {
            balance += diff;
            return true;
        }
    }
};


#endif