# MyQtApp.pro
TEMPLATE = app
TARGET = MyQtApp
CONFIG += c++11

# Thêm các thư mục con vào project
SOURCES += MainApplication.cpp \
           Controller/DataController.cpp \
           Model/Product.cpp \
           Model/Cart.cpp \
           Model/User.cpp \
           View/GiaoDienKhachHang.cpp
HEADERS +=  Controller/DataController.h \
            Datastructures/Pair.h \
            Datastructures/Vector.h \
            Model/Product.h \
            Model/Cart.h \
            Model/User.h \
            View/GiaoDienKhachHang.h
           
# Thêm thư viện cần thiết
QT += widgets

# Khai báo tài nguyên
RESOURCES += Resource/resources.qrc