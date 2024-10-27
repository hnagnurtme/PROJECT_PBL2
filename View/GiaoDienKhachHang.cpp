#include "View/GiaoDienKhachHang.h"
#include "Model/Product.h"
#include "Datastructures/Vector.h"
#include "Controller/DataController.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFile>
#include <QTextStream>
#include <QStackedWidget>
#include <QDate>
#include <QDir>

CustomerInterface::CustomerInterface(QWidget *parent) : QWidget(parent) {
    QFile file("Resource/style.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString style = stream.readAll();
        this->setStyleSheet(style);
    }
    
    setFixedSize(1500, 800);
    setWindowTitle("Customer Homepage");

    QPushButton *showOverviewButton = new QPushButton("Overview");
    QPushButton *showProductsButton = new QPushButton("Products");
    QPushButton *showCartButton = new QPushButton("Cart");
    QPushButton *showOrdersButton = new QPushButton("Your Orders");
    QPushButton *showAccountButton = new QPushButton("Account Information");
    QPushButton *checkoutButton = new QPushButton("Logout");

    showOverviewButton->setObjectName("showOverviewButton");
    showProductsButton->setObjectName("showProductsButton");
    showCartButton->setObjectName("showCartButton");
    showOrdersButton->setObjectName("showOrdersButton");
    showAccountButton->setObjectName("showAccountButton");
    checkoutButton->setObjectName("checkoutButton");

    connect(showOverviewButton, &QPushButton::clicked, this, &CustomerInterface::showOverview);
    connect(showProductsButton, &QPushButton::clicked, this, &CustomerInterface::showProducts);
    connect(showCartButton, &QPushButton::clicked, this, &CustomerInterface::showCart);
    connect(showOrdersButton, &QPushButton::clicked, this, &CustomerInterface::showOrders);
    connect(showAccountButton, &QPushButton::clicked, this, &CustomerInterface::showAccount);
    connect(checkoutButton, &QPushButton::clicked, this, &CustomerInterface::checkout);

    QWidget *menuWidget = new QWidget();
    QVBoxLayout *menuLayout = new QVBoxLayout(menuWidget);
    menuWidget->setFixedSize(200, 800);

    menuLayout->addSpacing(50);
    menuLayout->addWidget(showOverviewButton);
    menuLayout->addSpacing(10);
    menuLayout->addWidget(showProductsButton);
    menuLayout->addSpacing(10);
    menuLayout->addWidget(showCartButton);
    menuLayout->addSpacing(10);
    menuLayout->addWidget(showOrdersButton);
    menuLayout->addSpacing(100);
    menuLayout->addWidget(showAccountButton);
    menuLayout->addSpacing(10);
    menuLayout->addWidget(checkoutButton);
    menuLayout->addSpacing(50);

    stackWidget = new QStackedWidget();
    QLineEdit *searchLineEdit = new QLineEdit();
    searchLineEdit->setFixedHeight(50);
    searchLineEdit->setPlaceholderText("Search by product name...");
    connect(searchLineEdit, &QLineEdit::textChanged, this, &CustomerInterface::filterProducts);

    productTable = new QTableWidget(5, 6);
    productTable->setHorizontalHeaderLabels({"No.", "Description", "Product ID", "Product Name", "Price", "Quantity", "Add to Cart"});
    productTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    productTable->setColumnWidth(0, 30);

    QGroupBox *productGroupBox = new QGroupBox();
    QVBoxLayout *productLayout = new QVBoxLayout(productGroupBox);
    productLayout->addWidget(searchLineEdit);
    productLayout->addSpacing(20);
    productLayout->addWidget(productTable);

    cartTable = new QTableWidget(0, 6);
    cartTable->setHorizontalHeaderLabels({"No.", "Product Name", "Color", "Size", "Quantity", "Price"});
    cartTable->setFixedSize(700, 600);

    QTextEdit *invoiceDisplay = new QTextEdit("Invoice");
    invoiceDisplay->setVisible(false);
    QPushButton *placeOrderButton = new QPushButton("Place Order");
    placeOrderButton->setObjectName("placeOrderButton");
    connect(placeOrderButton, &QPushButton::clicked, this, &CustomerInterface::showInvoice);
    
    QGroupBox *invoiceGroupBox = new QGroupBox();
    QVBoxLayout *invoiceLayout = new QVBoxLayout(invoiceGroupBox);
    invoiceLayout->addWidget(invoiceDisplay);
    invoiceLayout->addWidget(placeOrderButton);
    
    QHBoxLayout *cartAndInvoiceLayout = new QHBoxLayout();
    QGroupBox *cartAndInvoiceBox = new QGroupBox();
    cartAndInvoiceBox->setLayout(cartAndInvoiceLayout);
    cartAndInvoiceLayout->addWidget(cartTable);
    cartAndInvoiceLayout->addWidget(invoiceGroupBox);

    stackWidget->addWidget(productGroupBox);
    stackWidget->addWidget(cartAndInvoiceBox);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(menuWidget);
    layout->addWidget(stackWidget);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);
    showProducts();
}

void CustomerInterface::addProductsData() {
    productTable->clearContents();
    productTable->setRowCount(0);  // Xóa toàn bộ hàng trước đó

    DataController loadData("D:/PBL/Data/ProductInformation.csv"); 
    Vector<Product> products = loadData.loadProductData(); 

    size_t productCount = products.getSize(); 
    int row = 0;

    // Kiểm tra kích thước của products
    qDebug() << "Number of products loaded:" << productCount;

    for (size_t i = 0; i < productCount && row < 100; ++i) {
        productTable->insertRow(row); 
        productTable->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        productTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(products[i].getDescription()))); 
        productTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(products[i].getProductId()))); 
        productTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(products[i].getName()))); 
        productTable->setItem(row, 4, new QTableWidgetItem(QString::number(products[i].getPrice()))); 
        productTable->setItem(row, 5, new QTableWidgetItem(QString::number(products[i].getStock()))); 

        QPushButton *addProductsButton = new QPushButton("Add");
        addProductsButton->setObjectName("confirmButton");
        connect(addProductsButton, &QPushButton::clicked, [this, row]() { addProducts(row, false); });

        QHBoxLayout *actionLayout = new QHBoxLayout();
        actionLayout->addWidget(addProductsButton); 

        QWidget *actionWidget = new QWidget();
        actionWidget->setLayout(actionLayout);
        productTable->setCellWidget(row, 6, actionWidget); 

        row++; 
    }

    for (int i = 0; i < row; ++i) {
        productTable->setRowHeight(i, 100);
    }

    if (productTable->rowCount() == 0) {
        qDebug() << "Product table is empty.";
    }
}



void CustomerInterface::showProducts() {
    productTable->clear();
    productTable->setRowCount(100);
    productTable->setColumnCount(7);

    int rowHeight = 100;
    for (int row = 0; row < productTable->rowCount(); ++row) {
        productTable->setRowHeight(row, rowHeight);
    }

    productTable->setHorizontalHeaderLabels({"No.", "Description", "Product ID", "Product Name", "Price", "Quantity", "Add to Cart"});
    addProductsData();

    stackWidget->setCurrentIndex(0);
}

void CustomerInterface::showCart() {
    {}
}

void CustomerInterface::showOverview() {
    {}
}

void CustomerInterface::filterProducts() {
    {}
}

void CustomerInterface::addProducts(int row, bool fromCart) {
    {}
}

void CustomerInterface::deleteProducts(int row, bool fromCart) {
}

void CustomerInterface::showAccount() {
}

void CustomerInterface::checkout() {
}

void CustomerInterface::showInvoice(){
}

void CustomerInterface::showOrders(){
}
