#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

#include "user.h"
#include "seller.h"

using namespace std;

// Class representing a product
class Product {
private:
    long int id;
    string name;
    string category;
    double price;
    Seller* seller;  // Pointer to the seller who listed the product
public:
    // Constructor for initializing product data
    Product(string& pname, string& pcategory, double pprice, Seller* pseller) :
            name(pname), category(pcategory), price(pprice), seller(pseller) {}

    // Display product information
    void display_info() {
        cout << name << "\nId: " << id << "\nCategory: " << category << "\nPrice: " <<
             price << "$" << "\nSeller: " << seller->get_username() << endl;
    }

    // Getter functions for accessing private member variables
    string get_name() {
        return name;
    }

    string get_category() {
        return category;
    }

    double get_price() {
        return price;
    }

    Seller* get_seller() {
        return seller;
    }
};

#endif