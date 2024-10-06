# MyQtApp.pro
TEMPLATE = app
TARGET = MyQtApp
CONFIG += c++11

# Thêm các thư mục con vào project
SOURCES += MAIN_APPLICATION.cpp \
           GUI/Source/LoginWindow.cpp \
           GUI/Source/RegisterWindow.cpp \
           GUI/Source/HomePage.cpp \
           GUI/Source/ForgotPasswordWindow.cpp \
           Controller/Source/HomepageController.cpp 

HEADERS += GUI/Header/LoginWindow.h \
           GUI/Header/RegisterWindow.h \
           GUI/Header/HomePage.h \
           GUI/Header/ForgotPasswordWindow.h \
           Controller/Header/HomepageController.h 

# Thêm thư viện cần thiết
QT += widgets
