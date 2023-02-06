#ifndef COMMON_H
#define COMMON_H


#define QUESTION_NUM 5
// 5xxx用户操作指令
enum
{
    OK = 5000,
    REGISTER = 5001,
    LOGIN,
    SINGLE_GETQUESTION,
    RANK,
    ANSWER,
    RANKRESULT,
    UPDATE
};


// 8xxx 错误 
enum
{
    ERROR = 8001,
    USER_EXIST,
    PWorNAME_ERROR,
    USER_LOGIN

};





#endif // COMMON_H
