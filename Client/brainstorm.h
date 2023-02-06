#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include "communicate.h"

namespace Ui {
class BrainStorm;
}

class BrainStorm : public QDialog
{
    Q_OBJECT

public:
    explicit BrainStorm(Communicate *_com, QJsonObject &json, QWidget *parent = 0);
    ~BrainStorm();

private:
    //单人训练从服务器获取题目
    void singleGetQuestion();

    //单人训练设置题目
    void singleSetQuestion();

    //单人训练答题
    void singleAnswerQuestion(int select);

//-------rank-----------
    //设置得分
    void setEnemyStatus();
    void setSelfStatus();

    //rank设置问题
    void rankSetQuestion();
    //rank答题
    void rankAnswerQuestion(int select);
    //rank结果
    void rankSetResult(QJsonObject &json);

private slots:
    void on_SingleTrainButton_clicked();

    void on_single_back_clicked();

    void on_single_start_clicked();

    //单人训练从服务接收题目
    void rcvSingleQuestion(QJsonObject json);

    void singleTimerOut();

    void on_pushButton_2_clicked();

    void on_singleSelect1_clicked();

    void on_singleSelect2_clicked();

    void on_singleSelect3_clicked();

    void on_singleSelect4_clicked();

    void on_RankButton_clicked();

    //接受排位
    void Rank(QJsonObject json);

    void rankTimerOut();

    void on_rankSelect1_clicked();

    void on_rankSelect2_clicked();

    void on_rankSelect3_clicked();

    void on_rankSelect4_clicked();

    void on_pushButton_clicked();

private:
    Ui::BrainStorm *ui;

    Communicate *_com;//通信类指针 负责和服务器通信

    QJsonObject _singleQuestion;
    int _currentSingleQuestionIndex; //当前回答哪一个问题的下标
    QTimer _singleTimer;             //定时器
    int _singleSec;                  //时间倒数
    int _singleScore;


    //------------------------rank-----------------
    QJsonObject _rankQuestion;
    QString _enemyName;
    QString _enemyRank;
    int _enemyScore;

    int _rankSec;
    int _myScore;

    QString _userName;
    QString _userRank;

    int _currentRankQuestionIndex;
    int _enemyRankQuestionIndex;

    QTimer _rankTimer;

};

#endif // BRAINSTORM_H
