#ifndef FORGOTPASSWORDWINDOW_H
#define FORGOTPASSWORDWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class ForgotPassWordWindow : public QWidget {
    Q_OBJECT

public:
    explicit ForgotPassWordWindow(QWidget *parent = nullptr);

signals:
    void closed(); 

private slots:
    void sendOTPRequest();
    void confirmOTP(); 
    void backtoLogin(); 

private:
    QLineEdit *emailLineEdit; 
    QPushButton *sendButton; 
    QPushButton *confirmButton; 
    QPushButton *backtologinButton; 
    QLineEdit *otpLineEdit; 
};

#endif // FORGOTPASSWORDWINDOW_H
