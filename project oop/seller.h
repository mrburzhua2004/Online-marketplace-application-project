#ifndef PROJECT_OOP_SELLER_H
#define PROJECT_OOP_SELLER_H

#include <iostream>
#include <string>
#include <vector>

#include "user.h"
#include "customer.h"

// Structure representing a sale, containing customer and product information
struct Sale {
    Customer* customer;
    string product_name;
};

// Derived class representing a seller, inheriting from User
class Seller : public User {
private:
    int rating;
    int number_of_rates;
    vector<Sale> sales;
public:
    // Constructor for initializing seller data
    Seller(string& username, string& email, string& password) :
            User(username, email, password) {
        rating = 3;
        number_of_rates = 1;
    }

    // Override the display_info function to provide seller-specific information
    void display_info() override {
        cout << "\nName: " << username << "\nEmail: " << email << "\nRating: " << rating << endl;
    }

    // Add a sale record to the seller's history
    void add_sale(Customer* customer, string product_name, double price) {
        sales.push_back({ customer, product_name });
    }

    // Display sales information and allow the seller to learn more about a purchase
    void display_sales() {
        short user_input;
        int nr = 1;
        for (auto& sale : sales) {
            cout << nr << ". User " << sale.customer->get_username() << " purchased your " << sale.product_name;
            nr++;
            cout << "\n                                   1. Learn more" <<
                 "\n                                   2. Skip" << endl;
            cin >> user_input;
            if (user_input == 1) {
                sales[user_input - 1].customer->display_info();
                cin >> user_input;
            }
        }
    }

    // Update seller's rating based on new user rating
    void update_rating(int new_rate) {
        number_of_rates++;
        rating = (rating * number_of_rates + new_rate) / number_of_rates;
    }
};

#endif
