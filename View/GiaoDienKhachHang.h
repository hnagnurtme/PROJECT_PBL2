#pragma once

#include <QMap>
#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QStackedWidget>
#include <QVector>
#include <QStringList>
#include <QTextEdit>
#include <QLabel>
#include <QString>

class CustomerInterface : public QWidget {
    Q_OBJECT

public:
    CustomerInterface(QWidget *parent = nullptr);
private slots:
    void showOverview();
    void showProducts();
    void filterProducts();
    void showCart();
    void showOrders();
    void showAccount();
    void showInvoice();
    void checkout();
signals:
    void productAdded(const QString &productName);
    void productDeleted(const QString &productName);

private:
    QVector<QStringList> gioHang;
    QPushButton *showOverviewButton;
    QPushButton *showProductsButton;
    QPushButton *checkoutButton;
    QPushButton *showCartButton;
    QPushButton *showOrdersButton;
    QPushButton *showInvoicesButton;
    QPushButton *showAccountButton;
    QStackedWidget *stackWidget;

    QTableWidget *productTable;
    QTableWidget *cartTable;
    QTableWidget *ordersTable;
    QLabel *TongTien;
    void addProducts(int row, bool fromCart);
    void deleteProducts(int row, bool fromCart);
    void addProductsData();
};
