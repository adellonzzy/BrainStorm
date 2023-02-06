#include "login.h"
#include "ui_widget.h"
#include "register.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _com = new Communicate();

    connect(_com, SIGNAL(login(QJsonObject)), this, SLOT(login(QJsonObject)));
    connect(ui->PWlineEdit, SIGNAL(returnPressed()), this, SLOT(on_sign_in_clicked()));
    connect(ui->UserNamelineEdit, SIGNAL(returnPressed()), this, SLOT(on_sign_in_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sign_in_clicked()
{
    QString userName = ui->UserNamelineEdit->text();
    QString passwd = ui->PWlineEdit->text();

    //将登陆信息发送给服务器
    QJsonObject json;
    json["cmd"]      = LOGIN;
    json["userName"] = userName;
    json["passwd"]   = passwd;


    _com->writeData(json);
}

void Widget::login(QJsonObject json)
{
    int result = json["result"].toInt();
    switch (result)
    {
    case OK:
    {
        this->hide();
        BrainStorm *dlg = new BrainStorm(_com, json);
        dlg->show();
        dlg->setAttribute(Qt::WA_DeleteOnClose);

    }
        break;
    case ERROR:
        QMessageBox::critical(this, "登录", "未知错误");
        break;
    case PWorNAME_ERROR:
        QMessageBox::critical(this, "登录", "账号或密码错误");
        break;
    case USER_EXIST:
        QMessageBox::critical(this, "登录", "登录失败，不允许重复");
        break;
    default:
        break;
    }
}

void Widget::on_sign_up_clicked()
{
    this->hide();
    Register reg(_com);
    reg.exec();
    this->show();
}
