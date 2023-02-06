#ifndef MYSERVER_H
#define MYSERVER_H

#include "tcpserver.h"
#include "user.h"
#include <spdlog/spdlog.h>
#include "db.h"
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include "../common.h"
#include <string>
#include <map>
#include <mutex>

//#define DEBUG


class MyServer:public TcpServer
{
public:
    MyServer();

    void connectEvent(TcpSocket *);
    void readEvent(TcpSocket *);
    void writeEvent(TcpSocket *);
    void closeEvent(TcpSocket *, short );

private:
    //发送数据
    void writeData(TcpSocket *s, const Json::Value &inJson);

    //用户注册
    void Register(TcpSocket *s, const Json::Value &inJson);

    //用户登录
    void Login(TcpSocket *s, const Json::Value &inJson);

    //个人训练获取题目
    void singleGetQuestion(TcpSocket* s);

//--------------rank---------------
    //进行排位赛
    void Rank(TcpSocket* s);

    //开始对战
    void startRank(TcpSocket* first, TcpSocket* second);

    //rank结果
    void rankResult(TcpSocket* s, const Json::Value &inJson);

    //初始化段位积分对照表
    void initRankMap();

    //rank回答一道问题
    void rankAnswerOneQuestion(TcpSocket *s, const Json::Value &inJson);

private:
    std::shared_ptr<spdlog::logger> _log;//记录日志句柄
    DB *_db; //数据库句柄

    //键是用户名，值是用户指针
    std::mutex _userLock;
    std::map<std::string, User*> _users; //在线用户列表

    //key   rank积分
    //value 对应的段位说明
    std::map<int, std::string> _rankMap; //rank积分对比表

    //key rank积分
    //value 参与排位的socket句柄
    std::mutex _rankLock;
    std::map<int, TcpSocket*> _rankQueue;
};

#endif // MYSERVER_H
