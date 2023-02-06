#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <mutex>
#include <spdlog/spdlog.h>
#include <jsoncpp/json/json.h>

class DB
{
public:
    DB(const char *host, const char *userName, const char *passwd, const char *dbName);

    //执行数据库语句
    bool db_exec(const char *sql);

    //数据库查询
    bool db_select(const char *sql, Json::Value &outjson);



private:
    std::mutex _mutex; //数据库句柄互斥锁
    MYSQL *_mysql; //数据库句柄


};

#endif // DB_H
