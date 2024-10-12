#include "GUI/Header/ForgotPasswordWindow.h"
#include "UserService/Header/HomepageController.h"
#include "GUI/Header/ChangePasswordWindow.h"
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
    setFixedSize(1100, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Group for Email Input
    QGroupBox *emailGroupBox = new QGroupBox("Email Recovery", this);
    QVBoxLayout *emailLayout = new QVBoxLayout(emailGroupBox);

    QLabel *emailLabel = new QLabel("Enter your email:", this);
    emailLayout->addWidget(emailLabel);

    emailLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Email");
    emailLayout->addWidget(emailLineEdit);

    sendButton = new QPushButton("Send Request", this);
    emailLayout->addWidget(sendButton);
    emailGroupBox->setLayout(emailLayout);

    // Group for OTP Input
    QGroupBox *otpGroupBox = new QGroupBox("OTP Verification", this);
    QVBoxLayout *otpLayout = new QVBoxLayout(otpGroupBox);

    QLabel *otpLabel = new QLabel("Enter your OTP:", this);
    otpLayout->addWidget(otpLabel);

    otpLineEdit = new QLineEdit(this);
    otpLineEdit->setPlaceholderText("OTP");
    otpLineEdit->setVisible(false); 
    otpLayout->addWidget(otpLineEdit);

    confirmButton = new QPushButton("Confirm OTP", this);
    confirmButton->setVisible(false);
    otpLayout->addWidget(confirmButton);
    otpGroupBox->setLayout(otpLayout);

    // Back to Login Button
    backtologinButton = new QPushButton("Back to Login", this);

    // Connect Signals and Slots
    connect(sendButton, &QPushButton::clicked, this, &ForgotPassWordWindow::sendOTPRequest);
    connect(backtologinButton, &QPushButton::clicked, this, &ForgotPassWordWindow::backtoLogin);
    connect(confirmButton, &QPushButton::clicked, this, &ForgotPassWordWindow::confirmOTP);

    // Image and Title Layout
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

    QLabel *title = new QLabel("Recover your password ");
    title->setStyleSheet("font-size: 30px; font-weight: bold; color: #112950 ;");
    title->setAlignment(Qt::AlignCenter);
    imageLayout->addWidget(title);
    
    QGroupBox *imageGroup = new QGroupBox();
    imageGroup->setLayout(imageLayout);
    imageGroup->setStyleSheet("background-color: #BDDDFD;color : white; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");

    // Set styles
    setStyleSheet("background-color: white");
    emailGroupBox->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    otpGroupBox->setStyleSheet("background-color: #BDDDFD; border: 1px solid #AAAAAA; border-radius: 5px; padding: 10px;");
    sendButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    backtologinButton->setStyleSheet("background-color: #D4696A; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");
    confirmButton->setStyleSheet("background-color: #112950; color: white; border-radius: 5px; padding: 10px; font-size: 16px;");

    // Add Groups to Main Layout
    mainLayout->addWidget(imageGroup);
    mainLayout->addWidget(emailGroupBox);
    mainLayout->addWidget(otpGroupBox);
    mainLayout->addWidget(backtologinButton);
    

    setLayout(mainLayout); // Set main layout for the window
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
        string otpSend = otpEntered.toStdString();
        QMessageBox::information(this, "Success", "OTP is valid. You can now reset your password");
        
        ChangePasswordWindow *changePasswordWindow = new ChangePasswordWindow(this, otpSend);
        changePasswordWindow->setWindowFlag(Qt::Window);
        changePasswordWindow->resize(1000, 600);
        changePasswordWindow->show();

        
    
        // Kết nối tín hiệu destroyed
    } else {
        // Nếu OTP không hợp lệ
        QMessageBox::warning(this, "Invalid OTP", "The OTP you entered is invalid. Please try again.");
    }
}

void ForgotPassWordWindow::backtoLogin() {
    // Thêm logic của hàm backtoLogin ở đây
    emit closed();  // Giả sử bạn đang muốn đóng cửa sổ Forgot Password
}