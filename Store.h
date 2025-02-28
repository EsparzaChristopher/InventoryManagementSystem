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
void addProduct(Product<T>& p);
private:
Product<T>* inventory;
int numProducts;
int numSpace;
};
#include "Store.h"

using namespace std;
template <typename T>
Store<T> :: Store(int space){
   numSpace = space;
   numProducts = 0;
   inventory = new Product<T>[numSpace];
}
template <typename T>
Store<T> :: ~Store(){
    delete [] inventory;
}
template <typename T>
void Store<T> :: addProduct(Product<T>& p){
    cout << "NUMPRODUCTS" << numProducts << endl << numSpace;
    if(numProducts >= numSpace){
        numSpace *= 2;
        Product<T>* tempArray = new Product<T>[numSpace];
        for(int i = 0; i < numProducts; i++){
            tempArray[i] = inventory[i];
        }
        delete [] inventory;
        inventory = tempArray;
    }
    inventory[numProducts] = p;
    numProducts++;
    
}
template <typename T>
void Store<T> :: applyDiscount(Product<T>& p, double percentage){ 
    for(int i = 0; i < numProducts; i++ ){
        if(inventory[i] == p){
            inventory[i].setPrice(inventory[i].getPrice() *(1 - (percentage/100)));
            p = inventory[i];
        }
    }
        
}
#endif