#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#define IP_ADDR "192.168.59.208"
#define PORT_ID 9999

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "../common.h"

class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QObject *parent = nullptr);

    void writeData(const QJsonObject &json);
signals:
    void rstResult(int);

    void login(QJsonObject json);

    void rcvSingleQuestion(QJsonObject json);

    void Rank(QJsonObject json);

public slots:
    void readData();

private:
    QTcpSocket s;

};

#endif // COMMUNICATE_H
