#include "GUI/Header/HomePage.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>

HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    setFixedSize(1100, 700);  // Đặt kích thước cửa sổ cố định

    // Tạo layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Tạo QLabel để hiển thị hình nền
    backgroundLabel = new QLabel(this);

    // Load hình ảnh từ file
    originalPixmap = QPixmap("D:/PBL2/GUI/Resouce/Background1.png");

    // Đặt hình ảnh vào QLabel ban đầu
    backgroundLabel->setPixmap(originalPixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    backgroundLabel->setScaledContents(true);

    // Thêm QLabel vào layout
    layout->addWidget(backgroundLabel);

    // Set layout cho widget
    setLayout(layout);
    setWindowTitle("Home Page");
}

// Override sự kiện resizeEvent để phóng to/thu nhỏ hình ảnh khi cửa sổ thay đổi kích thước
void HomePage::resizeEvent(QResizeEvent *event) {
    // Scale hình ảnh để phù hợp với kích thước của cửa sổ cố định (1000x600)
    backgroundLabel->setPixmap(originalPixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    QWidget::resizeEvent(event);  // Gọi lại sự kiện resize gốc
}
