#pragma once
#include "Model/User.h"
#include "Model/Product.h"
#include "Datastructures/Vector.h"
#include "Datastructures/Pair.h"
#include <string>
#include <iostream>

using namespace std;

class Cart {
private:
    Vector<Pair<Product, int>> items;
    string customerID;

public:
    Cart(string id ="");
    void setCartID(string id);
    void addItem(const Product& product, int quantity);
    void removeItem(string productId);
    void clearCart();
    void displayCartItems() const;
    Vector<Pair<Product, int>> getItems() const;
    string getCustomerID() const;
    bool contains(const std::string& productId) const;
    void reduceItem(const string& productId, int quantity);
};
