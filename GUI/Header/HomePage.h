#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>

class HomePage : public QWidget {
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;  // Override sự kiện resize

private:
    QLabel *backgroundLabel;  // QLabel để hiển thị hình ảnh nền
    QPixmap originalPixmap;   // QPixmap để lưu trữ hình ảnh gốc
};

#endif // HOMEPAGE_H
