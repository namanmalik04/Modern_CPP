#include "5424870_MD5_Inventory_headerfile.h"

// Default Constructor
Inventory::Inventory() {
    description_of_product = "Unknown";
    balance_stock = 30;  // Default > 20
    productcode = 0;
}

// Parameterized Constructor
Inventory::Inventory(string desc, int stock, int code) {
    if (stock <= 20)
        throw invalid_argument("Initial stock must be greater than 20");
    description_of_product = desc;
    balance_stock = stock;
    productcode = code;
}

// Purchase Function
void Inventory::purchase(int qty) {
    balance_stock += qty;
    cout << "After purchase stock: " << balance_stock << endl;
}

// Sale Function
void Inventory::sale(int qty) {
    balance_stock -= qty;
    if (balance_stock < 20) {
        throw runtime_error("Low stock level");
    }
    cout << "After sale stock: " << balance_stock << endl;
}

// Display Function
void Inventory::display() const {
    cout << "Product: " << description_of_product
         << ", Code: " << productcode
         << ", Stock: " << balance_stock << endl;
}

// Getter
int Inventory::getProductCode() const {
    return productcode;
}

// Global Function Search
void Search(Inventory arr[], int size, int code) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].getProductCode() == code) {
            cout << "Product found" << endl;
            arr[i].display();
            return;
        }
    }
    cout << "Exception: \"Product not found\"" << endl;
}
