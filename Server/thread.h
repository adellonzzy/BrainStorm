#ifndef THREAD_H
#define THREAD_H

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/event_struct.h>
#include <event2/event_compat.h>
#include <event2/listener.h>
class Thread
{
public:
    Thread();

    void start(); //线程运行

    struct event_base *getBase();

protected:
    static void* worker(void* arg);
    static void pipeRead(evutil_socket_t, short, void *);
    void run();
private:
    struct event_base *m_base;

    pthread_t m_threadId;

    int m_pipeReadFd;
    int m_pipeWriteFd;
    struct event m_pipeEvent;
};

#endif // THREAD_H
