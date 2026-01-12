#include "5424870_MD5_Inventory_refactored_headerfile.h"

int main() {
    try {
        std::cout << "=== Test Case 1 ===" << std::endl;
        Inventory iobj("Sample", 30, 1001);

        iobj.sale(5);   // 25
        iobj.sale(4);   // 21
        iobj.purchase(10); // 31

        try {
            iobj.sale(25); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Exception: \"" << e.what() << "\"" << std::endl;
        }

        std::cout << "\n=== Test Case 3 ===" << std::endl;
        Inventory iarr[3] = {
            {"Household", 100, 50111},
            {"Electronics", 500, 50112},
            {"Sports", 300, 50113}
       };

        Search(iarr, 3, 50112);  // Product found
        Search(iarr, 3, 99999);  // Product not found
    }
    catch (const std::exception& e) {
        std::cout << "Exception: \"" << e.what() << "\"" << std::endl;
    }

    return 0;
}
