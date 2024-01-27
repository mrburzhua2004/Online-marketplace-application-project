#ifndef PROJECT_OOP_DATABASE_H
#define PROJECT_OOP_DATABASE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "product.h"
#include "seller.h"
#include "customer.h"

using namespace std;

// Function pointers for accessing Customer, Seller, and Product attributes
string (Customer::*customer_methods[])() = {&Customer::get_username, &Customer::get_email};
string (Seller::*seller_methods[])() = {&Seller::get_username, &Seller::get_email};
string (Product::*product_methods[])() = {&Product::get_name, &Product::get_category};


// Base class representing a database
class Database {
protected:
    virtual int get_size() {};
};

#endif

