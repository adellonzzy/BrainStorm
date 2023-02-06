#include "tcpserver.h"

TcpServer::TcpServer(int threadNum): m_nextThread(0)
{
    if(threadNum <= 0)
    {
        printf("threadNum <= 0\n");
        exit(-1);
    }

    m_threadNum = threadNum;
    m_threadPool = new Thread[threadNum];
    if(m_threadPool == NULL)
    {
        printf("创建线程池出错。\n");
        exit(-1);
    }

    m_base = event_base_new();
    if(!m_base)
    {
        printf("线程初始化失败\n");
        exit(-1);
    }
}

void TcpServer::listenCb(struct evconnlistener *, evutil_socket_t fd, struct sockaddr *clientAddr, int , void *data)
{
    TcpServer *p = (TcpServer*)data;
    p->listenEvent(fd,(struct sockaddr_in*)clientAddr);
}

void TcpServer::listenEvent(evutil_socket_t fd,struct sockaddr_in *clientAddr)
{
    char* ip = inet_ntoa(clientAddr->sin_addr);
    uint16_t port = ntohs(clientAddr->sin_port);


    //从线程池中选择一个线程取处理客户端的请求
    //以轮询的方式选择线程
    struct event_base *base = m_threadPool[m_nextThread].getBase();
    m_nextThread = (m_nextThread + 1)%m_threadNum;
    struct bufferevent *bev;
    bev = bufferevent_socket_new(m_base,fd, BEV_OPT_CLOSE_ON_FREE);
    if(!bev)
    {
        printf("Error constructing bufferevent!\n");
        event_base_loopbreak(base);
        return;
    }

    TcpSocket *s = new TcpSocket(this,bev,ip,port);

    //单独封装
    bufferevent_setcb(bev, s->readEventCb, s->writeEventCb, s->closeEventCb, s);
    bufferevent_enable(bev, EV_WRITE);
    bufferevent_enable(bev, EV_READ);
    bufferevent_enable(bev, EV_SIGNAL);


    //调用客户端连接函数
    connectEvent(s);

}


int TcpServer::listen(int port, const char *ip)
{
    sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    if(ip != NULL)
    {
        inet_aton(ip, &sin.sin_addr);
    }
    m_listener = evconnlistener_new_bind(m_base, listenCb, this,
                         LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
                         (struct sockaddr*)&sin, sizeof (sin));
    if(!m_listener)
    {
        printf("Could not create a listener!\n");
        return -1;
    }

    //开启线程池
     for(int i =0; i < m_threadNum; i++)
     {
         m_threadPool[i].start();
         //printf("线程 %d 启动\n", i+1);
     }
    return 0;
}


void TcpServer::start()
{
    printf("服务器启动！\n");

    event_base_dispatch(m_base);

    evconnlistener_free(m_listener);

    event_base_free(m_base);

    printf("done\n");
}
