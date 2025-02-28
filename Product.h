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
    //get the price
    T getPrice() const;
    // Method chaining with `this`
    Product<T>& setPrice(T newPrice);
    Product<T>& setStock(int newStock);
 
    // Static method for random stock generation
    static int generateStock(int min, int max);
};

// Default constructor
template <typename T>
Product<T>::Product() : name("Unknown"), productID(0), price(0), stock(0) {}
 
// Parameterized constructor
template <typename T>
Product<T>::Product(string name, T price, int stock) : name(name), price(price), stock(stock) {
    static int idCounter = 100;
    productID = idCounter++;
}
 
// Overloaded + operator
template <typename T>
Product<T> Product<T>::operator+(int quantity) {
    this->stock += quantity;
    return *this;
}
 
// Overloaded - operator
template <typename T>
Product<T> Product<T>::operator-(int quantity) {
    if (stock >= quantity)
        stock -= quantity;
    return *this;
}
 
// Overloaded == and != operators
template <typename T>
bool Product<T>::operator==(const Product<T>& other) const {
    return this->productID == other.productID;
}
 
template <typename T>
bool Product<T>::operator!=(const Product<T>& other) const {
    return !(*this == other);
}
 
// Overloaded << operator
template <typename T>
ostream& operator<<(ostream& os, const Product<T>& p) {
    os << "Product: " << p.name << " | ID: " << p.productID << " | Price: $" << p.price << " | Stock: " << p.stock << endl;
    return os;
}
 
// Overloaded >> operator
template <typename T>
istream& operator>>(istream& is, Product<T>& p) {
    cout << "Enter product name, price, and stock: ";
    is >> p.name >> p.price >> p.stock;
    return is;
}
 
// Method chaining
template <typename T>
Product<T>& Product<T>::setPrice(T newPrice) {
    this->price = newPrice;
    return *this;
}
 
template <typename T>
Product<T>& Product<T>::setStock(int newStock) {
    this->stock = newStock;
    return *this;
}
 
// Random stock generator
template <typename T>
int Product<T>::generateStock(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}
template <typename T> 
T Product<T> :: getPrice() const{
    return price;
}

 
#endif