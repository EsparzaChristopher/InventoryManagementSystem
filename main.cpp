#include "Product.h"
#include "Store.h"
 
int main() {
    Product<double> laptop("Laptop", 999.99, Product<double>::generateStock(10, 50));
    Product<double> phone("Phone", 599.99, 20);
 
    cout << "Initial Inventory:\n";
    cout << laptop << phone;
 
    // Sell a product
    laptop = laptop - 5;
 
    cout << "After Selling 5 Laptops:\n";
    cout << laptop;
 
    // Apply discount
    applyDiscount(laptop, 10);
    cout << "After 10% Discount on Laptop:\n";
    cout << laptop;
 
    return 0;
}