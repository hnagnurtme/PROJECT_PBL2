#pragma once
#include "Model/Product.h"
#include  "Datastructures/Vector.h"
#include <vector>
#include <string>
using namespace std; 

class DataController {
public:
    DataController(const string& filename);
    Vector<Product> loadProductData(); 

private:
    string productFileName;
    Product parseProduct(const string& line);
};

