#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "thread.h"
#include "tcpsocket.h"
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/event_struct.h>
#include <event2/event_compat.h>
#include <event2/listener.h>


class TcpSocket;

class TcpServer
{
    friend class TcpSocket;
public:
    TcpServer(int threadNum = 8);

    int listen(int port, const char *ip = NULL);

    //服务器开始运行
    void start();
protected:
    //监听回调函数，有客户端连接的时候就会调用整函数
    static void listenCb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *data);

    void listenEvent(evutil_socket_t fd,struct sockaddr_in *);

    //---------虚函数 去具体处理客户端的逻辑----------
    virtual void connectEvent(TcpSocket *)=0;
    virtual void readEvent(TcpSocket *)=0;
    virtual void writeEvent(TcpSocket *)=0;
    virtual void closeEvent(TcpSocket *, short )=0;

private:
    int m_threadNum; //线程个数
    Thread *m_threadPool;//线程池

    struct event_base *m_base;
    struct evconnlistener *m_listener;//监听客户端的连接

    int m_nextThread;
};

#endif // TCPSERVER_
