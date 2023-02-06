#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "tcpserver.h"
#include "string"

class TcpServer;

class TcpSocket
{
public:
    TcpSocket(TcpServer *tcpServer,struct bufferevent *bev,char *ip, uint16_t port);

    //可读事件回调函数
    static void readEventCb(struct bufferevent *bev, void *ctx);

    static void writeEventCb(struct bufferevent *bev, void *ctx);

    static void closeEventCb(struct bufferevent *bev, short what, void *ctx);

    char* getIP();
    uint16_t getPort();

    //从客户端读数据
    int readData(void* data, int size);
    int writeData(const void *data, int size);

    void setUserName(std::string name);
    std::string getUserName();

private:
    static TcpServer *m_tcpServer;
    struct bufferevent *m_bev;
    char *m_ip;
    uint16_t m_port;

    std::string _userName;
};

#endif // TCPSOCKET_H
