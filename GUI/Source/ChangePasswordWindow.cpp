#include "GUI/Header/ForgotPasswordWindow.h"
#include "GUI/Header/ChangePasswordWindow.h"
#include "UserService/Header/HomepageController.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <string>
#include <QDebug>
using namespace std;
// Constructor
ChangePasswordWindow::ChangePasswordWindow(QWidget *parent, const string &otp)
    : QWidget(parent), otpEnter(otp) {

    setWindowTitle("Change Password");
    setFixedSize(400, 250); // Kích thước cố định của cửa sổ

    // Thiết lập layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Nhãn và trường nhập cho mật khẩu mới
    QLabel *passwordLabel = new QLabel("New Password:", this);
    passwordRecover = new QLineEdit(this);
    passwordRecover->setEchoMode(QLineEdit::Password);
    passwordRecover->setPlaceholderText("Enter new password...");

    // Nhãn và trường nhập để xác nhận mật khẩu
    QLabel *confirmLabel = new QLabel("Confirm Password:", this);
    passwordRecoverConfirm = new QLineEdit(this);
    passwordRecoverConfirm->setEchoMode(QLineEdit::Password);
    passwordRecoverConfirm->setPlaceholderText("Confirm new password...");

    // Nút gửi
    sendButton = new QPushButton("Send", this);
    connect(sendButton, &QPushButton::clicked, this, &ChangePasswordWindow::sendButtonClicked);

    // Thêm các widget vào layout
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordRecover);
    layout->addWidget(confirmLabel);
    layout->addWidget(passwordRecoverConfirm);
    layout->addWidget(sendButton);

    // Thiết lập layout cho cửa sổ
    setLayout(layout);
}
// Phương thức xử lý khi nút gửi được nhấn
void ChangePasswordWindow::sendButtonClicked() {
    QString password = passwordRecover->text().trimmed();
    QString confirmPassword = passwordRecoverConfirm->text().trimmed();

    // Kiểm tra các trường nhập
    if (password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in both fields.");
        return;
    }

    // Kiểm tra mật khẩu có khớp không
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Mismatch", "Passwords do not match.");
        return;
    }

    // Thực hiện thay đổi mật khẩu tại đây
    // Ví dụ: bạn có thể gọi hàm ChangePassword(email, password.toStdString())
    // Ở đây, bạn cần cung cấp email từ đâu đó trong mã của bạn
    HomepageController *recover;
    if(recover->RecoverPassword(otpEnter,password.toStdString()))
    QMessageBox::information(this, "Success", "Password has been changed successfully.");
    else
    QMessageBox::warning(this, "Password Mismatch", "HUhu");
    // Đóng cửa sổ nếu cần
    this->close();
}
