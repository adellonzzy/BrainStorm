#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "communicate.h"
#include "brainstorm.h"
#include <iostream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_sign_in_clicked();

    void on_sign_up_clicked();

    void login(QJsonObject json);

private:
    Ui::Widget *ui;

    Communicate *_com; //通信类指针 负责和服务器通信
};

#endif // LOGIN_H
