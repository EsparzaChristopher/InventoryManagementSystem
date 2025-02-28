#include "Product.h"
 
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
