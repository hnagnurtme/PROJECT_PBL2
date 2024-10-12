#include "GUI/Header/RegisterWindow.h"
#include "Controller/Header/HomepageController.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <string> 
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(1100, 700);
    
    // Set up UI elements
    QLabel *nameLabel = new QLabel("Full Name:");
    nameEdit = new QLineEdit();
    nameEdit->setPlaceholderText("Enter your full name...");

    QLabel *emailLabel = new QLabel("Email Address:");
    emailEdit = new QLineEdit();
    emailEdit->setPlaceholderText("Enter your email...");

    QLabel *passwordLabel = new QLabel("Password:");
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("Enter your password...");

    QLabel *confirmPasswordLabel = new QLabel("Confirm Password:");
    confirmPasswordEdit = new QLineEdit();
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setPlaceholderText("Confirm your password...");

    termsCheckBox = new QCheckBox("I agree to the terms and conditions");

    QPushButton *registerButton = new QPushButton("Register");
    alreadyHaveAccount = new QPushButton("Already have an account? Log in");
    connect(alreadyHaveAccount, &QPushButton::clicked, this, &RegisterWindow::onAlreadyHaveAccountClicked);
    connect(registerButton, &QPushButton::clicked, this, &RegisterWindow::onRegisterButtonClicked);
    connect(this, &QWidget::destroyed, this, &RegisterWindow::closed);

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout;

    // Add a group for a label/message
    QVBoxLayout *imageLayout = new QVBoxLayout;
    QLabel *imageLabel = new QLabel();
    
    QPixmap pixmap("D:\\PBL2\\GUI\\Resouce\\Background1.png");
    if (pixmap.isNull()) {
        imageLabel->setText("Image not found");
    } else {
        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        imageLabel->setScaledContents(true);
    }

    QHBoxLayout *centerLayout = new QHBoxLayout;
    centerLayout->addStretch();
    centerLayout->addWidget(imageLabel);
    centerLayout->addStretch();

    imageLayout->addLayout(centerLayout);

    QLabel *title = new QLabel(" Welcome to my Store ");
    title->setStyleSheet("font-size: 20px; font-weight: bold; color: #112950 ;");
    title->setAlignment(Qt::AlignCenter);
    imageLayout->addWidget(title);
    
    QGroupBox *imageGroup = new QGroupBox();
    imageGroup->setLayout(imageLayout);
    imageGroup->setStyleSheet("background-color: #BDDDFD;color : white; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    imageGroup->setFixedSize(1100, 200);
    layout->addWidget(imageGroup);

    // Group for user details
    QGroupBox *userInfoGroup = new QGroupBox("User Information");
    QVBoxLayout *userInfoLayout = new QVBoxLayout;
    userInfoGroup->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    
    userInfoLayout->addWidget(nameLabel);
    userInfoLayout->addWidget(nameEdit);
    userInfoLayout->addWidget(emailLabel);
    userInfoLayout->addWidget(emailEdit);
    userInfoLayout->addWidget(passwordLabel);
    userInfoLayout->addWidget(passwordEdit);
    userInfoLayout->addWidget(confirmPasswordLabel);
    userInfoLayout->addWidget(confirmPasswordEdit);
    userInfoGroup->setLayout(userInfoLayout);
    layout->addWidget(userInfoGroup);
    
    // Add terms and conditions checkbox
    layout->addWidget(termsCheckBox);

    // Group for buttons
    QGroupBox *buttonGroup = new QGroupBox();
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(registerButton);
    buttonLayout->addSpacing(20); // Add spacing between buttons
    buttonLayout->addWidget(alreadyHaveAccount);
    buttonGroup->setLayout(buttonLayout);
    buttonGroup->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px");

    layout->addWidget(buttonGroup);

    setLayout(layout);
    setWindowTitle("Register");

    // Apply styles
    setStyleSheet("background-color: white");
    nameEdit->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 5px;");
    emailEdit->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 5px;");
    passwordEdit->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 5px;");
    confirmPasswordEdit->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 5px;");
    termsCheckBox->setStyleSheet("color: #FFFFFF");

    registerButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    alreadyHaveAccount->setStyleSheet("background-color: #112950; color : white; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px; font-size : 16px");
    termsCheckBox->setStyleSheet("color : black");

}

void RegisterWindow::onRegisterButtonClicked() {
    // Handle register button click
    QString name = nameEdit->text();
    QString email = emailEdit->text();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();

    if (name.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Error", "Passwords do not match.");
        return;
    }

    if (!termsCheckBox->isChecked()) {
        QMessageBox::warning(this, "Terms and Conditions", "You must agree to the terms and conditions.");
        return;
    }

    // Registration successful (you can customize this logic)
    QMessageBox::information(this, "Registration Successful", "Your account has been created.");
    {
    HomepageController save;
    save.saveAccount(email.toStdString(), password.toStdString());  
    }
    emit closed();
}

void RegisterWindow::onAlreadyHaveAccountClicked() {
    emit closed();
}
