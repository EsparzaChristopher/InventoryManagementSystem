#include "Store.h"

using namespace std;
template <typename T>
Store<T> :: Store(int space){
   numSpace = space;
   inventory = new Product<T>[numSpace];
}
template <typename T>
Store<T> :: ~Store(){
    delete [] inventory;
}
template <typename T>
void Store<T> :: addProduct(Product<T>& p){
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
        }
    }
        
}