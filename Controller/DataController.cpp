#include "Controller/DataController.h"
#include "Datastructures/Vector.h"
#include "Datastructures/Pair.h"
#include "Model/Product.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
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
    getline(ss, colorsStr, ';');
    getline(ss, brand, ';');

    double price = stod(priceStr);
    int stock = stoi(stockStr);

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

    return Product(id, name, category, price, stock, description,colors, brand);
}

void DataController::saveCartData(const Cart& cart) {
    string folderPath = "Data/CartInformation";
    
    // Tạo thư mục nếu không tồn tại
    if (!filesystem::exists(folderPath)) {
        filesystem::create_directory(folderPath);
    }

    // Đường dẫn tới file cart
    string filePath = folderPath + "/" + cart.getCustomerID() + "_cart.csv";
    
    // Mở file để ghi đè (trunc sẽ là mặc định khi mở với ofstream)
    ofstream file(filePath);

    // Kiểm tra xem file có mở thành công không
    if (!file.is_open()) {
        cerr << "Không thể mở file để ghi: " << filePath << endl;
        return;
    }

    // Ghi tiêu đề cột
    file << "Product Name,Product ID,Price,Quantity\n";
    
    // Sử dụng lớp Vector để ghi dữ liệu
    const Vector<Pair<Product, int>>& cartItems = cart.getItems();
    for (long i = 0; i < cartItems.getSize(); ++i) {
        const Product& product = cartItems[i].getFirst();
        int quantity = cartItems[i].getSecond();
        file << product.getName() << ","
             << product.getProductId() << ","
             << product.getPrice() << ","
             << quantity << "\n";
    }

    // Đóng file
    file.close();
}

Cart DataController::loadCartData(const string& customerID) {
    Cart cart(customerID);
    string filePath = "Data/CartInformation/" + customerID + "_cart.csv";
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Không thể mở file để đọc: " << filePath << endl;
        return cart; // Trả về giỏ hàng rỗng nếu không thể mở file
    }

    string line;
    // Bỏ qua dòng tiêu đề
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, id;
        double price;
        int quantity;

        // Đọc dữ liệu từ dòng
        getline(ss, name, ',');
        getline(ss, id, ',');
        ss >> price;
        ss.ignore(); // Bỏ qua dấu phẩy
        ss >> quantity;

        // Tạo sản phẩm và thêm vào giỏ hàng
        Product product(id, name, "", price, 0, "", Vector<string>(), ""); // Gọi constructor Product phù hợp
        cart.addItem(product, quantity); // Giả sử bạn có phương thức addItem để thêm sản phẩm vào giỏ hàng
    }

    file.close();
    return cart;
}
