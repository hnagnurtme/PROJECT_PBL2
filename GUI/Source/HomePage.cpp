#include "GUI/Header/HomePage.h"
#include <QVBoxLayout>
#include <QLabel>


HomePage::HomePage(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    
    QLabel *messageLabel = new QLabel("Đây là homepage", this);
    messageLabel->setStyleSheet("color : blue; font-size :20; bold" );
    messageLabel->setAlignment(Qt::AlignCenter); 

    
    layout->addWidget(messageLabel);

    
    setLayout(layout);
    setWindowTitle("Home Page");
}

