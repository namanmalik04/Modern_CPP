#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <stdexcept>

class Inventory {
private:
    std::string m_descriptionOfProduct;
    int m_balanceStock;
    int m_productCode;

    static const int MIN_STOCK_LEVEL = 20;

public:
    // Constructors
    Inventory();
    Inventory(const std::string& description, int stock, int code);

    // Member Functions
    void purchase(int quantity);
    void sale(int quantity);
    void display() const;

    // Getter
    int getProductCode() const;
    std::string getDescription() const;
    int getBalanceStock() const;
};

// Global Function
void Search(Inventory arr[], int size, int code);

#endif
