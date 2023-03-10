#include "register.h"
#include "ui_register.h"
#include <QMessageBox>

Register::Register(Communicate *com, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    _com = com;

    connect(_com, SIGNAL(rstResult(int)), this, SLOT(rstResult(int)));
}

Register::~Register()
{
    delete ui;
}

void Register::on_sign_up_clicked()
{
    QString userName = ui->UserNamelineEdit->text();
    QString passwd = ui->PWlineEdit->text();

    //发送注册信息
    QJsonObject json;
    json["cmd"]      = REGISTER;
    json["userName"] = userName;
    json["passwd"]   = passwd;

    //给服务器发送数据
    _com->writeData(json);

}

void Register::on_go_back_clicked()
{
    this->close();
}

void Register::rstResult(int ret)
{
    switch (ret)
    {
    case OK:
        QMessageBox::information(this, "注册", "注册成功");
        break;
    case ERROR:
        QMessageBox::critical(this, "注册", "注册失败，未知错误");
        break;
    case USER_EXIST:
        QMessageBox::critical(this, "注册", "注册失败，用户已经存在");
        break;
    default:
        break;
    }
}
