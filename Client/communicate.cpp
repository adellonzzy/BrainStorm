#include "communicate.h"

Communicate::Communicate(QObject *parent) : QObject(parent)
{

    //连接服务器
    s.connectToHost(QHostAddress(IP_ADDR), 9999);
    connect(&s, SIGNAL(readyRead()), this, SLOT(readData()));
}

void Communicate::readData()
{
    QByteArray data;
    while(s.bytesAvailable())
    {
        data += s.readAll();
    }

    //数据解析
    QJsonDocument dt = QJsonDocument::fromJson(data);
    if(dt.isNull())
    {
        return;
    }
    QJsonObject root = dt.object();

    //具体的逻辑处理
    int cmd = root["cmd"].toInt();
    switch (cmd)
    {
    case REGISTER:
        emit rstResult(root["result"].toInt());
        break;
    case LOGIN:
        emit login(root);
        break;
    case SINGLE_GETQUESTION:
        emit rcvSingleQuestion(root["question"].toObject());
        break;
    case RANK :
        emit Rank(root);
        break;
    case ANSWER :
        emit Rank(root);
        break;
    case RANKRESULT:
        emit Rank(root);
        break;
    default:
        break;
    }
}

void Communicate::writeData(const QJsonObject &json)
{
    QJsonDocument d(json);
    QByteArray sendData = d.toJson();
    int len = sendData.size();


    s.write((char*)&len, sizeof(int)); //发送数据长度
    s.write(sendData);                 //发送数据
}
