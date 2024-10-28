#include "Model/Product.h"
#include <iostream>

Product::Product(string id, const string& name, const string& category, double price, int stock,
                const string& description, const Vector<string>& colors, const string& brand)
    : productId(id), name(name), category(category), price(price), stock(stock),
    description(description), colors(colors), brand(brand) {}

string Product::getProductId() const {
    return productId;
}

string Product::getName() const {
    return name;
}

string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

string Product::getDescription() const {
    return description;
}

Vector<string> Product::getColors() const {
    return colors;
}

string Product::getBrand() const {
    return brand;
}

void Product::setName(const string& newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setStock(int newStock) {
    stock = newStock;
}

void Product::setDescription(const string& newDescription) {
    description = newDescription;
}

void Product::displayInfo() const {
    cout << "Product ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Price: $" << price << endl;
    cout << "Stock: " << stock << endl;
    cout << "Description: " << description << endl;
    cout << endl;
    cout << "Colors: ";
    for (long i = 0; i < colors.getSize(); ++i) {
        cout << colors[i] << " ";
    }
    cout << endl;
    cout << "Brand: " << brand << endl;
}

bool Product::isAvailable(int requestedQuantity) const {
    return requestedQuantity <= stock;
}
