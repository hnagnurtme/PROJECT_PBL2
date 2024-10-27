#include "Model/Cart.h"
#include "Model/Product.h"
#include <iostream>
using namespace std;


void Cart::addItem(const Product& product, int quantity) {
    if (quantity <= 0) {
        cerr << "Quantity must be greater than 0." << endl;
        return;
    }
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].getFirst().getProductId() == product.getProductId()) {
            items[i].setSecond(items[i].getSecond() + quantity);
            return;
        }
    }
    items.pushback(Pair<Product, int>(product, quantity));
}

void Cart::removeItem(string productId) {
    for (int i = 0; i < items.getSize(); ++i) {
        if (items[i].getFirst().getProductId() == productId) {
            items.remove(i);
            return;
        }
    }
    cerr << "Product with ID " << productId << " not found in the cart." << endl;
}

void Cart::clearCart() {
    while (!items.isEmpty()) {
        items.popback();
    }
}

void Cart::displayCartItems() const {
    if (items.isEmpty()) {
        cout << "The cart is empty." << endl;
        return;
    }
    cout << "Cart items:" << endl;
    for (int i = 0; i < items.getSize(); ++i) {
        cout << "Product ID: " << items[i].getFirst().getProductId()
            << ", Name: " << items[i].getFirst().getName() 
            << ", Quantity: " << items[i].getSecond() << endl;
    }
}

Vector<Pair<Product, int>> Cart::getItems() const {
    return items;
}

string Cart::getCustomerID() const {
    return customerID;
}
