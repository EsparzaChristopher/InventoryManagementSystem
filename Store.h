#ifndef STORE_H
#define STORE_H
#include "Product.h"
#include "iostream"
#include "random"
using namespace std;
template <typename T>
class Store {
public:
//function template applys discounts on all products

void applyDiscount(Product<T>& p, double percentage);
Store(int space = 10);
~Store();
void addProduct(string n, T p, int s);

private:
Product<T>* inventory;
int numProducts;
int numSpace;
};
#endif