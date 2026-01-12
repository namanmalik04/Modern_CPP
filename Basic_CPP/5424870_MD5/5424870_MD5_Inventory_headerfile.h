#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Inventory {
private:
    string description_of_product;
    int balance_stock;
    int productcode;

public:
    // Default Constructor
    Inventory();

    // Parameterized Constructor
    Inventory(string desc, int stock, int code);

    // Purchase Function
    void purchase(int qty);

    // Sale Function
    void sale(int qty);

    // Display Function
    void display() const;

    // Getters for Search
    int getProductCode() const;
};

// Global Function
void Search(Inventory arr[], int size, int code);

#endif
