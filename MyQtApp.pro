# MyQtApp.pro
TEMPLATE = app
TARGET = MyQtApp
CONFIG += c++11

# Thêm các thư mục con vào project
SOURCES += MainApplication.cpp \
           GiaoDienKhachHang.cpp  
HEADERS +=  GiaoDienKhachHang.h
           
# Thêm thư viện cần thiết
QT += widgets

# Khai báo tài nguyên
RESOURCES += Resource/resources.qrc