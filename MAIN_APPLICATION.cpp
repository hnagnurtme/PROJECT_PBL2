#include <QApplication>
#include "GUI/Header/LoginWindow.h" 
#include "GUI/Header/ChangePasswordWindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    LoginWindow loginWindow;
    loginWindow.setWindowTitle("Login Form");
    loginWindow.resize(1000,600);
    loginWindow.show();
    return app.exec();
}
