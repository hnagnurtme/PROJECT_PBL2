#include "GUI/Header/RegisterWindow.h"
#include "GUI/Header/LoginWindow.h"
#include "GUI/Header/HomePage.h"
#include "GUI/Header/ForgotPasswordWindow.h"
#include "Controller/Header/HomepageController.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    QLabel *emailLabel = new QLabel("Email Address:");
    emailEdit = new QLineEdit();
    emailEdit->setPlaceholderText("Enter your email...");

    QLabel *passwordLabel = new QLabel("Password:");
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("Enter your password...");

    rememberMeCheckBox = new QCheckBox("Remember me for 14 days");

    QPushButton *loginButton = new QPushButton("Log in");
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    QPushButton *registerButton = new QPushButton("Register");
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);

    QPushButton *forgotPasswordButton = new QPushButton("Forgot Password?");
    connect(forgotPasswordButton, &QPushButton::clicked, this, &LoginWindow::onForgotPasswordButtonClicked);

    QVBoxLayout *imageLayout = new QVBoxLayout;
    QLabel *imageLabel = new QLabel();
    
    QPixmap pixmap("D:\\PBL2\\GUI\\Resouce\\IMG_180.JPG");
    if (pixmap.isNull()) {
        imageLabel->setText("Image not found");
    } else {
        imageLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));
    }

    QHBoxLayout *centerLayout = new QHBoxLayout;
    centerLayout->addStretch();
    centerLayout->addWidget(imageLabel);
    centerLayout->addStretch();

    imageLayout->addLayout(centerLayout);

    QLabel *title = new QLabel("Helooo My Name Linh Khum");
    title->setStyleSheet("font-size: 36px; font-weight: bold; color: #112950 ;");
    title->setAlignment(Qt::AlignCenter);
    imageLayout->addWidget(title);
    
    QGroupBox *imageGroup = new QGroupBox();
    imageGroup->setLayout(imageLayout);
    imageGroup->setStyleSheet("background-color: #BDDDFD;color : white; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    
    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->addWidget(emailLabel);
    inputLayout->addWidget(emailEdit);
    inputLayout->addWidget(passwordLabel);
    inputLayout->addWidget(passwordEdit);
    inputLayout->addWidget(rememberMeCheckBox);

    QGroupBox *inputGroup = new QGroupBox();
    inputGroup->setLayout(inputLayout);
    inputGroup->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(forgotPasswordButton);

    QGroupBox *buttonGroup = new QGroupBox;
    buttonGroup->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    buttonGroup->setLayout(buttonLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(imageGroup);
    mainLayout->addWidget(inputGroup);
    mainLayout->addWidget(buttonGroup);
    imageLayout->setContentsMargins(30, 10, 30, 10);
    inputLayout->setContentsMargins(30, 10, 30, 10);
    buttonLayout->setContentsMargins(30, 10, 30, 10);

    setLayout(mainLayout);
    resize(1000, 600);
    setStyleSheet("background-color: white");

    QString inputStyle = "background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 5px;";
    emailEdit->setStyleSheet(inputStyle);
    passwordEdit->setStyleSheet(inputStyle);
    rememberMeCheckBox->setStyleSheet("color: #112950;");

    loginButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    registerButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    forgotPasswordButton->setStyleSheet("background-color: #D4696A; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");

    setWindowTitle("Employer Log in");
    resize(300, 200);
}

void LoginWindow::onLoginButtonClicked() {
    QString email = emailEdit->text();
    QString password = passwordEdit->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both email and password.");
        return;
    }
    HomepageController author;
    if (author.LoginAuthentication(email.toStdString(), password.toStdString())) {
        QMessageBox::information(this, "Login Successful......", "Welcome!");
        this->hide();

        HomePage *mainWindow = new HomePage();
        mainWindow->resize(1000, 600);
        mainWindow->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
    }
}

void LoginWindow::onForgotPasswordButtonClicked() {

    ForgotPassWordWindow *forgotpassword = new ForgotPassWordWindow();

    // Kết nối tín hiệu đóng cửa sổ quên mật khẩu với lambda function để quay lại cửa sổ đăng nhập
    connect(forgotpassword, &ForgotPassWordWindow::closed, this, [this, forgotpassword]() {
        forgotpassword->close(); // Xóa cửa sổ quên mật khẩu
        this->show(); // Hiển thị lại cửa sổ đăng nhập
    });

    // Ẩn cửa sổ đăng nhập và hiển thị cửa sổ quên mật khẩu
    
    forgotpassword->show();
    this->hide();
}

void LoginWindow::onRegisterButtonClicked() {
    RegisterWindow *registerWindow = new RegisterWindow();
    connect(registerWindow, &RegisterWindow::closed, this, [this, registerWindow]() {
        registerWindow->close();
        this->show();
    });

    registerWindow->resize(900, 400);
    registerWindow->show();
    this->hide();
}
