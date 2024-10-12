#include "DataStructures/DataStructures.h"
#include <iostream>
#include <algorithm> // Để sử dụng std::copy

// Constructor mặc định
template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

// Constructor với sức chứa ban đầu
template <typename T>
Vector<T>::Vector(int initialCapacity) : capacity(initialCapacity), size(0) {
    data = new T[capacity];
}

// Constructor từ danh sách khởi tạo
template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : size(init.size()), capacity(init.size()) {
    data = new T[capacity];
    std::copy(init.begin(), init.end(), data);
}

// Constructor sao chép
template <typename T>
Vector<T>::Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    std::copy(other.data, other.data + size, data);
}

// Toán tử gán
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data; // Giải phóng bộ nhớ cũ
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] data; // Giải phóng bộ nhớ
}

// Lấy kích thước hiện tại
template <typename T>
int Vector<T>::getSize() const {
    return size;
}

// Lấy sức chứa hiện tại
template <typename T>
int Vector<T>::getCapacity() const {
    return capacity;
}

// Thêm phần tử vào cuối
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size >= capacity) {
        Resize();
    }
    data[size++] = value;
}

// Thêm phần tử vào đầu
template <typename T>
void Vector<T>::push_front(const T& value) {
    if (size >= capacity) {
        Resize();
    }
    for (int i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    ++size;
}

// Xóa phần tử ở cuối
template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw std::out_of_range("Cannot pop from an empty vector");
    }
}

// Xóa phần tử ở đầu
template <typename T>
void Vector<T>::pop_front() {
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    } else {
        throw std::out_of_range("Cannot pop from an empty vector");
    }
}

// Xóa phần tử tại chỉ số index
template <typename T>
void Vector<T>::erase(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// Toán tử truy cập
template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Toán tử truy cập cho const
template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Hàm thay đổi kích thước
template <typename T>
void Vector<T>::Resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2; // Tăng gấp đôi sức chứa
    T* newData = new T[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
