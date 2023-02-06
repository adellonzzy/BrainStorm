#include "myserver.h"

MyServer::MyServer()
{
#ifndef DEBUG
    _log = spdlog::stdout_color_mt("BrainStorm");
#else
    _log = spdlog::rotating_logger_mt("BrainStorm", "BrainStorm", 1024*1024*5, 3);
    _log->flush_on(spdlog::level::info);
#endif

    _db = new DB(NULL, "root", "", "BrainStorm");

    initRankMap();
}

void MyServer::connectEvent(TcpSocket *s)
{
    //printf("有一个新连接 %s : %d\n",s->getIP(),s->getPort());
    _log->info("有一个新连接 [{} : {}]",s->getIP(),s->getPort());
}

void MyServer::readEvent(TcpSocket *s)
{
    char buf[1024] = {0};
    while (1)
    {
        int len = 0;
        s->readData(&len, sizeof(len));
        if(len <= 0)
            break;

        s->readData(buf, len);

        //数据解析
        Json::Value root;
        Json::Reader reader; //json解析器
        if(!reader.parse(buf, root))
        {
            _log->error("json 数据解析失败");
            return;
        }
        int cmd = root["cmd"].asInt();
        switch (cmd)
        {
        case REGISTER:
            Register(s, root);
            break;
        case LOGIN:
            Login(s, root);
            break;
        case SINGLE_GETQUESTION:
            singleGetQuestion(s);
            break;
        case RANK:
            Rank(s);
            break;
        case ANSWER:
            rankAnswerOneQuestion(s, root);
            break;
        case RANKRESULT:
            rankResult(s, root);
            break;

        default:
            break;

        }
    }
}

void MyServer::writeEvent(TcpSocket *)
{

}

void MyServer::closeEvent(TcpSocket *s, short )
{
    //将用户从等待队列中删除
    {
        std::unique_lock<std::mutex> lock(_rankLock);
        int rank = _users[s->getUserName()]->getRank();
        auto it = _rankQueue.find(rank);
        if(it != _rankQueue.end())
        {
            _rankQueue.erase(it);
        }
    }

    std::unique_lock<std::mutex> lock(_userLock);
    std::map<std::string, User*>::iterator it = _users.begin();
    while(it != _users.end())
    {
        if(it->second->getSocket() == s)
        {
            _users.erase(it);
            _log->info("用户{}[{}:{}] logout", it->second->getName(), s->getIP(),s->getPort());

            //释放User
            delete  it->second;
            return;
        }
        it++;
    }

    _log->info("[{}:{}] logout", s->getIP(), s->getPort());
}

void MyServer::writeData(TcpSocket *s, const Json::Value &inJson)
{
    std::string data = inJson.toStyledString();
    s->writeData(data.c_str(), data.length());
}

void MyServer::Register(TcpSocket *s, const Json::Value &inJson)
{
    std::string userName = inJson["userName"].asString();
    std::string passwd   = inJson["passwd"].asString();

    // 检测用户是否已经存在

    char sql[100] = {0};
    sprintf(sql, "select *from user where name = '%s' and passwd = '%s'", userName.c_str(), passwd.c_str());
    int result = OK;
    Json::Value outjson;
    bool ret = _db->db_select(sql, outjson);
    if(!ret)
    {
        result = ERROR;
        _log->error("Register select user error");
    }
    if(outjson.isMember("name"))
    {
        result = USER_EXIST;
    }
    else
    {
        sprintf(sql, "insert into user(name, passwd, rank) values('%s', '%s', 0)",userName.c_str(), passwd.c_str());
        bool ret = _db->db_exec(sql);
        if(!ret)
        {
            result = ERROR;
            _log->error("Register insert user error");
        }
        else
        {
            _log->info("Register user = {} succeed", userName);
        }
    }
    Json::Value json;
    json["cmd"]    = REGISTER;
    json["result"] = result;

    writeData(s, json);
}

void MyServer::Login(TcpSocket *s, const Json::Value &inJson)
{
    std::string userName = inJson["userName"].asString();
    std::string passwd   = inJson["passwd"].asString();

    // 检测用户是否注册过
    int rank = 0;
    char sql[100] = {0};
    sprintf(sql, "select *from user where name = '%s' and passwd = '%s'", userName.c_str(), passwd.c_str());
    int result = OK;
    Json::Value outjson;
    bool ret = _db->db_select(sql, outjson);
    if(!ret)
    {
        result = ERROR;
        _log->error("Register select user error");
    }
    if(outjson.isMember("name")) //用户存在，表示已经注册过
    {
        std::unique_lock<std::mutex> lock(_userLock);
        if(_users.find(userName) != _users.end()) //用户已经登录
        {
            result = USER_LOGIN;
        }
        else
        {
            int i = 0;
            rank = atoi(outjson["rank"][i].asString().c_str());
            User* user = new User(userName, passwd, rank, s);
            _users.insert(make_pair(userName, user));
            _log->error("用户{} [{} : {}]", userName, s->getIP(), s->getPort());
            s->setUserName(userName);
        }
    }
    else
    {
        result = PWorNAME_ERROR;
    }


    Json::Value json;
    json["cmd"]      = LOGIN;
    json["result"]   = result;
    json["userName"] = userName;
    json["rank"]     = _rankMap[rank];

    writeData(s, json);
}

void MyServer::singleGetQuestion(TcpSocket* s)
{
    char sql[100] = {0};
    sprintf(sql, "select *from question order by rand() limit %d", QUESTION_NUM);

    int result = OK;
    Json::Value outjson;
    bool ret = _db->db_select(sql, outjson);
    if(!ret || outjson["question"].size() != QUESTION_NUM )
    {
        result = ERROR;
        _log->error("singleGetQuestion select question error");
    }

    Json::Value json;
    json["cmd"]      = SINGLE_GETQUESTION;
    json["result"]   = result;
    json["question"] = outjson;
    //json["rank"]     = rank;

    _log->info("用户{}[{}:{}] 获取题目 :{}\n",s->getUserName().c_str(), s->getIP(), s->getPort(), json.toStyledString());

    writeData(s, json);
}

//------------rank-------------------
//初始化段位
void MyServer::initRankMap()
{
    char buf[100] = {0};
    int rank = 0;
    int num = 0;
    for (int i =0; i < 100; i++)
    {
        if(i < 9)
        {
            rank = i / 3;
            num  = i % 3;
            sprintf(buf, "青铜%d %d颗星",3-rank, num+1);
        }
        else if(9 <= i && i < 18)
        {
            rank = (i-9) / 3;
            num  = (i-9) % 3;
            sprintf(buf, "白银%d %d颗星",3-rank, num+1);
        }
        else if(18 <= i && i < 34)
        {
            rank = (i-18) / 4;
            num  = (i-18) % 4;
            sprintf(buf, "黄金%d %d颗星",4-rank, num+1);
        }
        else if(34 <= i && i < 50)
        {
            rank = (i-34) / 4;
            num  = (i-34) % 4;
            sprintf(buf, "铂金%d %d颗星",4-rank, num+1);
        }
        else if(50 <= i && i < 75)
        {
            rank = (i-50) / 5;
            num  = (i-50) % 5;
            sprintf(buf, "钻石%d %d颗星",5-rank, num+1);
        }
        else if(75 <= i && i < 100)
        {
            rank = (i-75) / 5;
            num  = (i-75) % 5;
            sprintf(buf, "星耀%d %d颗星",5-rank, num+1);
        }
        _rankMap.insert(std::make_pair(i, buf));
    }
//    for(int i = 0; i < 100; i++)
//    {
//        std::cout << i << " : " << _rankMap[i] << std::endl;
//    }
}
//开始对战
void MyServer::startRank(TcpSocket* first, TcpSocket* second)
{
    char sql[100] = {0};
    sprintf(sql, "select *from question order by rand() limit %d", QUESTION_NUM);

    int result = OK;
    Json::Value outjson;
    bool ret = _db->db_select(sql, outjson);
    if(!ret || outjson["question"].size() != QUESTION_NUM )
    {
        result = ERROR;
        _log->error("startRank select question error");
    }

    Json::Value json;
    json["cmd"]      = RANK;
    json["result"]   = result;
    json["question"] = outjson;
    //json["rank"]     = rank;

    //  "enemyName":"root",
    //  "enemyRank":"黄金1 1颗星",
    //  "enemyScore":0

    //first user
    json["enemyName"] = second->getUserName();
    json["enemyRank"] = _rankMap[_users[second->getUserName()]->getRank()];
    json["enemyScore"] = 0;
    writeData(first, json);

    //second user
    json["enemyName"] = first->getUserName();
    json["enemyRank"] = _rankMap[_users[first->getUserName()]->getRank()];
    writeData(second, json);

    _log->info("获取 rank 题目 ：{}\n",json.toStyledString());

}
//进行排位赛
void MyServer::Rank(TcpSocket *s)
{
    TcpSocket *other = NULL;//对手socketfd

    User* user = _users[s->getUserName()];
    int rank = _users[s->getUserName()]->getRank(); //当前用户的 rank 积分

    //查找同一段位的对手
    std::unique_lock<std::mutex> lock(_rankLock);
    std::map<int, TcpSocket*>::iterator it = _rankQueue.find(rank);
    if(it != _rankQueue.end())
    {
        other = it->second;
        _rankQueue.erase(it);
    }
    else
    {
        //查找其他段位的选手，积分差值的绝对值小于5可以进行对战
        for(int i = 1; i <= 5; i++)
        {
            it = _rankQueue.find(rank + i);
            if(it != _rankQueue.end())
            {
                other = it->second;
                _rankQueue.erase(it);
                break;
            }
            it = _rankQueue.find(rank - i);
            if(it != _rankQueue.end())
            {
                other = it->second;
                _rankQueue.erase(it);
                break;
            }
        }
    }
    _log->info(" rank 分数:{}",rank);
    if(other == NULL) //没有匹配到用户
    {
        _rankQueue.insert(std::make_pair(rank, s));
        _log->info("当前等待 rank 人数:{}",_rankQueue.size());

    }
    else  //匹配到了
    {
        //开始对战
        startRank(s, other);
    }
}
//
void MyServer::rankAnswerOneQuestion(TcpSocket *s, const Json::Value &inJson)
{
    std::string enemyName = inJson["enemyName"].asString();
    User* user = _users[enemyName];

    Json::Value json;
    json["cmd"] = ANSWER;
    json["enemyscore"] = inJson["score"].asInt();
    json["enemyQuestionId"] = inJson["questionId"].asInt();

    writeData(user->getSocket(), json);
}
//
void  MyServer::rankResult(TcpSocket* s, const Json::Value &inJson)
{
    std::unique_lock<std::mutex> lock(_userLock);
    User* user = _users[s->getUserName()];

    int score = inJson["score"].asInt();
    int enemyScore = inJson["enemyScore"].asInt();

    if(score < enemyScore)
    {
        user->setRank(user->getRank()-1);
    }
    else if(score > enemyScore)
    {
        user->setRank(user->getRank()+1);
    }

    Json::Value json;
    json["cmd"] = RANKRESULT;
    json["newRank"] = _rankMap[user->getRank()];

    writeData(s, json);
}












