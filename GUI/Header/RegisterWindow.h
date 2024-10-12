#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class RegisterWindow : public QWidget {
    Q_OBJECT

public:
    RegisterWindow(QWidget *parent = nullptr);
signals:
    void closed();
private slots:
    void onRegisterButtonClicked();
    void onAlreadyHaveAccountClicked();

private:
    QLineEdit *nameEdit;
    QLineEdit *emailEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit;
    QCheckBox *termsCheckBox;
    QPushButton *alreadyHaveAccount;
};

#endif // REGISTERWINDOW_H
