#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <string>
using namespace std;
class ChangePasswordWindow : public QWidget {
    Q_OBJECT
public:
    // Khởi tạo với email và mã OTP (có thể tùy chọn)
    ChangePasswordWindow(QWidget *parent = nullptr, const string &otp = "");
signals:
    void closed();
private slots:
    // Phương thức xử lý khi nút gửi được nhấn
    void sendButtonClicked();

private:
    QLineEdit *passwordRecover;           // Để nhập mật khẩu mới
    QLineEdit *passwordRecoverConfirm;    // Để xác nhận mật khẩu mới
    QPushButton *sendButton;               // Nút gửi yêu cầu
    const string otpEnter;                  // Mã OTP để xác thực
};

#endif // CHANGEPASSWORDWINDOW_H
