#include "thread.h"

Thread::Thread()
{
    m_base = event_base_new();
    if(!m_base)
    {
        printf("Couldn't create an event_base: exiting\n");
        exit(-1);
    }

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(-1);
    }
    m_pipeReadFd = fd[0];
    m_pipeWriteFd = fd[1];

    //让管道事件监听管道的读端
    event_set(&m_pipeEvent, m_pipeReadFd, EV_READ | EV_PERSIST, pipeRead, this);
    //将事件添加到m_base集合中
    event_base_set(m_base,&m_pipeEvent);
    //开启事件的监听
    event_add(&m_pipeEvent,0);

}

void Thread::pipeRead(evutil_socket_t, short, void *)
{

}

void Thread::start()
{
    pthread_create(&m_threadId,NULL,worker,this);

    //设置线程分离属性
    pthread_detach(m_threadId);
}

void* Thread::worker(void* arg)
{
    Thread* p = (Thread*)arg;
    p->run();
    return NULL;
}

void Thread::run()
{
    //cout<<m_threadId<<" ";

    //监听base事件集合
    //cout<<"start...."<<endl;
    event_base_dispatch(m_base);//死循环 用来处理事件 类似Qt的exec()
                                //如果m_base事件集合内为空，则立刻返回
                                //初始化时需要给m_base添加事件，让它不空.
    event_base_free(m_base);

    cout<<m_threadId<<" finshed"<<endl;
}

struct event_base* Thread::getBase()
{
    return  m_base;
}

