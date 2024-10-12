#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <utility> // Để sử dụng std::pair
#include <stdexcept> // Để sử dụng std::out_of_range
#include <initializer_list> // Để sử dụng danh sách khởi tạo

template <typename T>
class Vector {
private:
    T* data;          // Con trỏ tới mảng lưu trữ
    int capacity;     // Sức chứa hiện tại của vector
    int size;         // Kích thước hiện tại (số lượng phần tử)

    void Resize();    // Hàm thay đổi kích thước

public:
    // Constructors
    Vector();                                 // Hàm khởi tạo mặc định
    Vector(int initialCapacity);              // Hàm khởi tạo với sức chứa ban đầu
    Vector(std::initializer_list<T> init);    // Hàm khởi tạo từ danh sách khởi tạo
    Vector(const Vector& other);               // Hàm khởi tạo sao chép
    Vector& operator=(const Vector& other);    // Toán tử gán
    ~Vector();                                // Hàm hủy

    // Các phương thức
    int getSize() const;                      // Lấy kích thước hiện tại
    int getCapacity() const;                  // Lấy sức chứa hiện tại
    void push_back(const T& value);           // Thêm phần tử vào cuối
    void push_front(const T& value);          // Thêm phần tử vào đầu
    void pop_back();                          // Xóa phần tử ở cuối
    void pop_front();                         // Xóa phần tử ở đầu
    void erase(int index);                    // Xóa phần tử tại chỉ số index
    T& operator[](int index);                 // Toán tử truy cập
    const T& operator[](int index) const;     // Toán tử truy cập cho const
};

#endif
