#include "GUI/Header/ForgotPasswordWindow.h"
#include "Controller/Header/HomepageController.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <string>
using namespace std;
ForgotPassWordWindow::ForgotPassWordWindow(QWidget *parent)
    : QWidget(parent) {
    
    setWindowTitle("Forgot Password");
    setFixedSize(700, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    QGroupBox *groupBox = new QGroupBox("Password Recovery", this);
    QVBoxLayout *layout = new QVBoxLayout(groupBox);

    QLabel *emailLabel = new QLabel("Enter your email:", this);
    layout->addWidget(emailLabel);

    emailLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Email");
    layout->addWidget(emailLineEdit);

    sendButton = new QPushButton("Send Request", this);
    layout->addWidget(sendButton);


    QLabel *otpLabel = new QLabel("Enter your OTP:", this);
    layout->addWidget(otpLabel);

    otpLineEdit = new QLineEdit(this);
    otpLineEdit->setPlaceholderText("OTP");
    otpLineEdit->setVisible(false); 
    layout->addWidget(otpLineEdit);

    confirmButton = new QPushButton("Confirm OTP", this);
    confirmButton->setVisible(false);
    layout->addWidget(confirmButton);

    backtologinButton = new QPushButton("Back to Login", this);
    layout->addWidget(backtologinButton);

    
    connect(sendButton, &QPushButton::clicked, this, &ForgotPassWordWindow::sendOTPRequest);
    connect(backtologinButton, &QPushButton::clicked, this, &ForgotPassWordWindow::backtoLogin);
    connect(confirmButton, &QPushButton::clicked, this, &ForgotPassWordWindow::confirmOTP);

    setStyleSheet("background-color: white");
    groupBox->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    sendButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    backtologinButton->setStyleSheet("background-color: #D4696A; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    confirmButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");

    // Thiết lập layout cho groupBox
    layout->setContentsMargins(30, 10, 30, 10);
    groupBox->setLayout(layout);
    mainLayout->addWidget(groupBox); // Thêm groupBox vào layout chính
    
    setLayout(mainLayout); // Thiết lập layout cho cửa sổ
}

void ForgotPassWordWindow::sendOTPRequest() {
    QString email = emailLineEdit->text().trimmed();
    HomepageController sendrequest;

    if (sendrequest.SendRequestRecover(email.toStdString())) {
        QMessageBox::information(this, "Request Sent", 
            "Password recovery request sent to " + email );

        // Hiển thị trường nhập OTP và nút xác nhận sau khi yêu cầu được gửi thành công
        otpLineEdit->setVisible(true); 
        confirmButton->setVisible(true); 
        sendButton->setEnabled(false); // Tạm thời vô hiệu hóa nút gửi yêu cầu sau khi gửi thành công
    } else {
        QMessageBox::warning(this, "Not Found", "Email address not found.");
    }
}

void ForgotPassWordWindow::confirmOTP() {
    QString otpEntered = otpLineEdit->text().trimmed();

    if (otpEntered.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter the OTP.");
        return;
    }

    HomepageController author;
    if (author.AuthentiacationRequest(otpEntered.toStdString())) {
        // Nếu OTP hợp lệ
        QMessageBox::information(this, "Success", "OTP is valid. You can now reset your password.");

        // Logic để chuyển đến trang thay đổi mật khẩu
        // ChangePasswordWindow *changePasswordWindow = new ChangePasswordWindow(this);
        // changePasswordWindow->show();
        // this->close(); // Đóng cửa sổ hiện tại nếu cần
    } else {
        // Nếu OTP không hợp lệ
        QMessageBox::warning(this, "Invalid OTP", "The OTP you entered is invalid. Please try again.");
    }
}

void ForgotPassWordWindow::backtoLogin() {
    // Thêm logic của hàm backtoLogin ở đây
    emit closed();  // Giả sử bạn đang muốn đóng cửa sổ Forgot Password
}