#ifndef PROJECT_OOP_PRODUCTS_DB_H
#define PROJECT_OOP_PRODUCTS_DB_H

#include <iostream>
#include <vector>
#include <fstream>

#include "product.h"
#include "seller.h"
#include "database.h"


// Database class for products
class Products_DB : public Database {
private:
    vector<Product> products;
public:
    int get_size() override {
        return products.size();
    }

    // Add a new product to the database
    Product* add(string pname, string pcategory, double pprice, Seller* pseller) {
        Product my_product(pname, pcategory, pprice, pseller);
        products.push_back(my_product);
        return &my_product;
    }

    // Find products based on a given key and attribute
    vector<Product*> find(string key, short attribute) {
        vector<Product*> found_products;
        for (auto& product : products) {
            if (key == (product.*product_methods[attribute])()) {
                found_products.push_back(&product);
            }
        }
        return found_products;
    }
};

#endif //PROJECT_OOP_PRODUCTS_DB_H
