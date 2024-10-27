#include "Controller/DataController.h"
#include "Datastructures/Vector.h"
#include "Datastructures/Pair.h"
#include "Model/Product.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

DataController::DataController(const string& filename) : productFileName(filename) {}

Vector<Product> DataController::loadProductData() {
    Vector<Product> products;
    ifstream file(productFileName);

    std::cout << "Trying to open file: " << productFileName << std::endl; 

    if (!file.is_open()) {
        throw runtime_error("Không thể mở file: " + productFileName);
    }

    string line;
    while (getline(file, line)) {
        Product product = parseProduct(line);
        products.pushback(product); 
    }

    file.close();
    return products;
}

Product DataController::parseProduct(const string& line) {
    istringstream ss(line);
    string id, name, category, priceStr, stockStr, description, sizesStr, colorsStr, brand;

    getline(ss, id, ';');         
    getline(ss, name, ';');
    getline(ss, category, ';');
    getline(ss, priceStr, ';');
    getline(ss, stockStr, ';');
    getline(ss, description, ';');
    getline(ss, sizesStr, ';');
    getline(ss, colorsStr, ';');
    getline(ss, brand, ';');

    double price = stod(priceStr);
    int stock = stoi(stockStr);

    
    Vector<Pair<int, int>> sizes;
    istringstream sizesStream(sizesStr);
    string sizePair;

    
    while (getline(sizesStream, sizePair, '}')) {
        if (sizePair.empty()) continue;

        
        if (sizePair.front() == '{') {
            sizePair.erase(sizePair.begin());
        }

        
        istringstream sizeStream(sizePair);
        int size, countOfSize;
        char delimiter;

        if (sizeStream >> size >> delimiter >> countOfSize) {
            sizes.pushback(Pair<int, int>{size, countOfSize}); 
        }
    }


    Vector<string> colors;
    istringstream colorsStream(colorsStr);
    string color;

    while (getline(colorsStream, color, ',')) {
        color.erase(remove(color.begin(), color.end(), '{'), color.end());
        color.erase(remove(color.begin(), color.end(), '}'), color.end());
        
        if (!color.empty()) {
            colors.pushback(color); 
        }
    }

    return Product(id, name, category, price, stock, description, sizes, colors, brand);
}

// Cart DataController::loadCartData(const string& filename) {
//     Cart cart("DefaultCustomerID");
//     ifstream file(filename);
//     string line;

//     if (file.is_open()) {
//         getline(file, line);
//         while (getline(file, line)) {
//             istringstream ss(line);
//             string customerId, productId;

//             getline(ss, customerId, ',');
//             getline(ss, productId, ',');
//             Product product = findProductById(productId);
//             if (product.getProductId() != "") { 
//                 cart.addItem(product, 1); 
//             }
//         }
//         file.close();
//     } else {
//         cout << "Không thể mở file giỏ hàng." << endl;
//     }
//     return cart;
// }
// Product DataController::findProductById(const string& productId) {
//     Vector<Product> products = loadProductData(); 
//     for (size_t i = 0; i < products.getSize(); ++i) { 
//         if (products[i].getProductId() == productId) {
//             return products[i]; 
//         }
//     }

//     return Product("", "", "", 0.0, 0, "", Vector<Pair<int, int>>(), Vector<string>(), ""); 
// }