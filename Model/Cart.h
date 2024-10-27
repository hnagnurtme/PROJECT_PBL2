#pragma once
#include "Model/User.h"
#include "Model/Cart.h"
#include "Model/Manager.h"
#include "Datastructures/Vector.h"
#include "Datastructures/Pair.h"
#include <string>
using namespace std;

class Cart {
private:
    Vector<Pair<Product, int>> items;
    string customerID;  
public:
    Cart(string id) : customerID(id) {}  
    void addItem(const Product& product, int quantity);
    void removeItem(string productId);
    void clearCart();
    void displayCartItems() const;
    Vector<Pair<Product, int>> getItems() const;
    string getCustomerID() const ;
};
