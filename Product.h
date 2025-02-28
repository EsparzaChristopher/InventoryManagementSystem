#ifndef PRODUCT_H
#define PRODUCT_H
 
#include <iostream>
#include <random>
using namespace std;
 
template <typename T>
class Product {
private:
    string name;
    int productID;
    T price;
    int stock;
 
public:
    // Constructors
    Product();
    Product(string name, T price, int stock);
    
    // Overloaded operators
    Product<T> operator+(int quantity); // Restock
    Product<T> operator-(int quantity); // Sell
    bool operator==(const Product<T>& other) const;
    bool operator!=(const Product<T>& other) const;
    // Friend function for I/O
    template <typename U>
    friend ostream& operator<<(ostream& os, const Product<U>& p);
    template <typename U>
    friend istream& operator>>(istream& is, Product<U>& p);
 
    // Method chaining with `this`
    Product<T>& setPrice(T newPrice);
    Product<T>& setStock(int newStock);
 
    // Static method for random stock generation
    static int generateStock(int min, int max);
};
 
#endif