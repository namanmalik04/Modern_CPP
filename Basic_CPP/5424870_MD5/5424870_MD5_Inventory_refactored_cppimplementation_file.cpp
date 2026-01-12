#include "5424870_MD5_Inventory_refactored_headerfile.h"

// Default Constructor
Inventory::Inventory()
    : m_descriptionOfProduct("Unknown"), m_balanceStock(30), m_productCode(0) {
    // Ensures stock > minimum
    if (m_balanceStock <= MIN_STOCK_LEVEL) {
        throw std::invalid_argument("Default stock must be greater than 20");
    }
}

// Parameterized Constructor
Inventory::Inventory(const std::string& description, int stock, int code)
    : m_descriptionOfProduct(description), m_balanceStock(stock), m_productCode(code) {
    if (stock <= MIN_STOCK_LEVEL) {
        throw std::invalid_argument("Initial stock must be greater than 20");
    }
}

// Purchase Function
void Inventory::purchase(int quantity) {
    if (quantity <= 0) {
        std::cout << "Invalid purchase quantity." << std::endl;
        return;
    }
    m_balanceStock += quantity;
    std::cout << "After purchase stock: " << m_balanceStock << std::endl;
}

// Sale Function
void Inventory::sale(int quantity) {
    if (quantity <= 0) {
        std::cout << "Invalid sale quantity." << std::endl;
        return;
    }

    m_balanceStock -= quantity;
    if (m_balanceStock < MIN_STOCK_LEVEL) {
        throw std::runtime_error("Low stock level");
    }
    std::cout << "After sale stock: " << m_balanceStock << std::endl;
}

// Display Function
void Inventory::display() const {
    std::cout << "Product: " << m_descriptionOfProduct
              << ", Code: " << m_productCode
              << ", Stock: " << m_balanceStock << std::endl;
}

// Getters
int Inventory::getProductCode() const { return m_productCode; }
std::string Inventory::getDescription() const { return m_descriptionOfProduct; }
int Inventory::getBalanceStock() const { return m_balanceStock; }

// Global Search Function
void Search(Inventory arr[], int size, int code) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].getProductCode() == code) {
            std::cout << "Product found:" << std::endl;
            arr[i].display();
            return;
        }
    }
    std::cout << "Exception: \"Product not found\"" << std::endl;
}
