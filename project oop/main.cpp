#include <iostream>
#include "string"
#include "database.h"
#include "user.h"
#include "seller.h"
#include "customer.h"
#include "sellers_DB.h"
#include "customers_DB.h"
#include "products_DB.h"

// Global instances of the databases and user input
Sellers_DB sellers;
Customers_DB customers;
Products_DB products;
short user_input;

// Seller User Interface
void seller_ui(Seller *current_user) {
    string pname, pcategory;
    double pprice;

    while (user_input != 4) {
        // Seller menu options
        cout << "\n                                   1. Account info"
             << "\n                                   2. Add product"
             << "\n                                   3. My sales"
             << "\n                                   4. Log out" << endl;

        cin >> user_input;

        switch (user_input) {
            case 1:
                current_user->display_info();
                current_user->show_balance();
                break;
            case 2:
                cout << "\n\nEnter the name of your product: ";
                cin >> pname;

                cout << "\nEnter the category of your product: ";
                cin >> pcategory;

                cout << "\nEnter the price of your product: ";
                cin >> pprice;

                // Add the new product to the products database
                products.add(pname, pcategory, pprice, current_user);
                cout << "\nYou have successfully added a new product.";
                break;
            case 3:
                current_user->display_sales();
                break;
            case 4:
                continue;
            default:
                cout << "\nInvalid input! Please try again." << endl;
        }
    }
}

// Customer User Interface
void customer_ui(Customer *current_user) {
    vector<Product *> found_products;
    int nr;
    string category;
    double amount;
    int user_rating;

    while (user_input != 4) {
        // Customer menu options
        cout << "\n                                   1. Account info"
             << "\n                                   2. Search"
             << "\n                                   3. Top up your balance"
             << "\n                                   4. Log out" << endl;

        cin >> user_input;

        switch (user_input) {
            case 1:
                current_user->display_info();
                current_user->show_balance();
                break;
            case 2:
                cout << "\nEnter category: ";
                cin >> category;

                // Search for products based on the provided category
                found_products = products.find(category, 1);

                while (user_input != 0) {
                    nr = 1;
                    for (auto &product: found_products) {
                        cout << "                                   " << nr << ". " << product->get_name() <<
                             " ___________ " << product->get_price() << "$" << endl;
                        nr++;
                    }
                    cout << "\nChoose to learn more (enter 0 to return): ";
                    cin >> user_input;

                    if (user_input != 0) {
                        Product *chosen_product = found_products[user_input - 1];
                        chosen_product->display_info();

                        while (user_input != 0) {
                            cout << "                                   0. Return"
                                 << "\n                                   1. Buy"
                                 << "\n                                   2. Seller" << endl;

                            cin >> user_input;

                            switch (user_input) {
                                case 1:
                                    // Process purchase and update seller's sales and rating
                                    if (current_user->update_balance(-chosen_product->get_price())) {
                                        chosen_product->get_seller()->add_sale(current_user,
                                                                               chosen_product->get_name(),
                                                                               chosen_product->get_price());

                                        chosen_product->get_seller()->update_balance(chosen_product->get_price());

                                        cout << "Transaction completed. You have purchased " << chosen_product->get_name()
                                             << " from " << chosen_product->get_seller()->get_username() << endl;

                                        cout << "Rate your purchase from 1 to 5:" << endl;
                                        cin >> user_rating;
                                        chosen_product->get_seller()->update_rating(user_rating);
                                    } else {
                                        cout << "Oops, not enough money. Top up your balance." << endl;
                                    }
                                    break;
                                case 2:
                                    chosen_product->get_seller()->display_info();
                                    break;
                                case 0:
                                    continue;
                                default:
                                    cout << "\nInvalid input! Please try again." << endl;
                            }
                        }
                    }
                }
                break;
            case 3:
                // Top up the customer's balance
                cout << "\nEnter an amount: ";
                cin >> amount;
                current_user->update_balance(amount);
                break;
            case 4:
                continue;
            default:
                cout << "\nInvalid input! Please try again." << endl;
        }
    }
}

// User login function
void log_in() {
    string username, password;

    cout << "\n                                   1. I am a seller"
         << "\n                                   2. I am a customer" << endl;
    cin >> user_input;

    cout << "Enter your username: " << endl;
    cin >> username;

    cout << "\nEnter your password: " << endl;
    cin >> password;

    if (user_input == 1) {
        // Check for the seller and log them in if credentials are correct
        Seller *found_seller = sellers.find(username, 0);
        if (found_seller == nullptr) {
            cout << "User doesn't exist." << endl;
        } else if (found_seller->get_password() == password) {
            cout << "Welcome back, our dear seller, " << found_seller->get_username() << endl;
            seller_ui(found_seller);
        } else {
            cout << "Wrong password!" << endl;
        }
    } else if (user_input == 2) {
        Customer *found_customer = customers.find(username, 0);
        if (found_customer == nullptr) {
            cout << "User doesn't exist." << endl;
        } else if (found_customer->get_password() == password) {
            cout << "Welcome back, our dear customer, " << found_customer->get_username() << endl;
            customer_ui(found_customer);
        } else {
            cout << "Wrong password!" << endl;
        }
    }
}

// User account creation function
void create_account() {
    string username, password, email, address;
    bool is_customer;

    cout << "\nSelect an account type:"
         << "\n                                   0. I am a seller"
         << "\n                                   1. I am a customer" << endl;
    cin >> is_customer;
    cin.ignore();

    cout << "\nEnter the name for your account: " << endl;
    getline(cin, username, '\n');

    cout << "\nEnter your password: " << endl;
    getline(cin, password, '\n');

    cout << "\nEnter your email: " << endl;
    getline(cin, email, '\n');

    if (is_customer) {
        cout << "\nEnter your address: " << endl;
        getline(cin, address, '\n');
        customers.add(username, email, password, address);
    } else {
        sellers.add(username, email, password);
    }
    cout << "\nCongratulations! You have successfully created your account." << endl;
}

int main() {
    // Populate the initial data
    sellers.add("Mike", "jo@mail.com", "12345");
    sellers.add("John", "john@example.com", "qwerty");
    sellers.add("Sara", "sara@mail.com", "saraPass789");
    sellers.add("Chris", "chris@example.com", "password123");
    sellers.add("Emily", "emily@email.com", "secure456");
    sellers.add("MEGA SHOP", "mega_shop@shop,com", "mega");

    customers.add("Edward", "edward@mail.com", "0000", "Apple str. 12");
    customers.add("Sophie", "sophie@example.com", "pass987", "Orange Ave. 34");
    customers.add("Michael", "michael@email.com", "mikePass123", "Banana St. 56");
    customers.add("Amanda", "amanda@example.com", "amandaPwd456", "Grape Blvd. 78");
    customers.add("Daniel", "daniel@mail.com", "danielPass789", "Cherry Lane 90");

    products.add("iPhone 14", "gadgets", 1000, sellers.find("Mike", 0));
    products.add("iPhone 15", "gadgets", 1200, sellers.find("Mike", 0));
    products.add("iPhone 13", "gadgets", 899.99, sellers.find("Mike", 0));
    products.add("Smart Home Hub", "home", 150, sellers.find("Mike", 0));
    products.add("Men's Jeans", "clothes", 50, sellers.find("Mike", 0));
    products.add("Running Shoes", "sport", 80, sellers.find("Mike", 0));
    products.add("Board Game - Settlers of Catan", "games", 49.56, sellers.find("John", 0));
    products.add("Skincare Set", "beauty and health", 65.20, sellers.find("John", 0));
    products.add("Desk Lamp", "home", 30.99, sellers.find("John", 0));
    products.add("Women's Sneakers", "clothes", 25.15,sellers.find("John", 0));
    products.add("Dumbbell Set", "sport", 199.99,sellers.find("Chris", 0));
    products.add("Nintendo Switch", "games", 399.99, sellers.find("Chris", 0));
    products.add("Hair Dryer", "beauty and health", 70.20,sellers.find("MEGA_SHOP", 0));
    products.add("Coffee Maker", "home", 80, sellers.find("MEGA_SHOP", 0));
    products.add("Backpack", "other", 25, sellers.find("MEGA_SHOP", 0));
    products.add("Yoga Mat", "sport", 20, sellers.find("MEGA_SHOP", 0));
    products.add("Digital Camera", "gadgets", 500, sellers.find("MEGA_SHOP", 0));
    products.add("Essential Oil Diffuser", "home", 35, sellers.find("MEGA_SHOP", 0));
    products.add("T-shirt", "clothes", 20, sellers.find("MEGA_SHOP", 0));
    products.add("iPhone 15", "gadgets", 1200, sellers.find("MEGA_SHOP", 0));

    while (true) {
        cout << "\n_____________Welcome to CraftyCrazeMarket_____________" << endl;
        cout << sellers.get_size() << " successful sellers, " << customers.get_size()
             << " happy customers and " << products.get_size() << " different products!" << endl;

        // Main menu options
        cout << "\n                                   1. Log in"
             << "\n                                   2. Create an account"
             << "\n                                   3. Exit" << endl;

        cin >> user_input;

        switch (user_input) {
            case 1:
                log_in();
                break;
            case 2:
                create_account();
                break;
            case 3:
                cout << "\nGoodbye! Thank you for visiting CraftyCrazeMarket.\n";
                return 0;
            default:
                cout << "\nInvalid input! Please try again." << endl;
        }
    }

}


