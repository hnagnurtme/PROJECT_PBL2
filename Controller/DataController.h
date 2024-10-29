#pragma once
#include "Model/Product.h"
#include "Model/Cart.h"
#include  "Datastructures/Vector.h"
#include <vector>
#include <string>
using namespace std; 

class DataController {
public:
    Product findProductById(const string& productId);
    DataController(const string& filename);
    Vector<Product> loadProductData(); 
    void saveCartData(const Cart& cart);       
    Cart loadCartData(const string& customerID);
private:
    string productFileName;
    Product parseProduct(const string& line);
};

