#include "brainstorm.h"
#include "ui_brainstorm.h"

BrainStorm::BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrainStorm)
{
    ui->setupUi(this);
    _com = com;

    _userName = json["userName"].toString();
    _userRank = json["rank"].toString();

    connect(&_singleTimer, SIGNAL(timeout()), this, SLOT(singleTimerOut()));
    connect(&_rankTimer, SIGNAL(timeout()), this, SLOT(rankTimerOut()));
    connect(_com, SIGNAL(rcvSingleQuestion(QJsonObject)), this, SLOT(rcvSingleQuestion(QJsonObject)));
    connect(_com, SIGNAL(Rank(QJsonObject)), this, SLOT(Rank(QJsonObject)));
}

BrainStorm::~BrainStorm()
{
    delete ui;
}


//进入个人训练
void BrainStorm::on_SingleTrainButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->singleMenu);
}
//个人训练 计时器
void BrainStorm::singleTimerOut()
{
    --_singleSec;
    if(_singleSec == 0)
    {
        ui->singleResult->setText("回答错误");
        QString str = QString("本次得分: %1").arg(_singleScore);
        ui->singleScoreResult->setText(str);
        _singleTimer.stop();
        ui->stackedWidget->setCurrentWidget(ui->singleScore);
    }
    ui->lcdNumber->display(_singleSec);
}
//个人训练 获取题目请求
void BrainStorm::singleGetQuestion()
{
    QJsonObject json;
    json["cmd"] = SINGLE_GETQUESTION;

    _com->writeData(json);
}
//个人训练设置题目
void BrainStorm::singleSetQuestion()
{
//    if(_currentSingleQuestionIndex == QUESTION_NUM)
//    {
//        ui->singleResult->setText("恭喜全部答对");
//        QString str = QString("本次得分: %1").arg(_singleScore);
//        ui->singleScoreResult->setText(str);
//        ui->stackedWidget->setCurrentWidget(ui->singleScore);
//        _singleTimer.stop();
//        return;
//    }
    ui->singleQuestion->setText(_singleQuestion["question"].toArray().at(_currentSingleQuestionIndex).toString());
    ui->singleSelect1->setText(_singleQuestion["selection1"].toArray().at(_currentSingleQuestionIndex).toString());
    ui->singleSelect2->setText(_singleQuestion["selection2"].toArray().at(_currentSingleQuestionIndex).toString());
    ui->singleSelect3->setText(_singleQuestion["selection3"].toArray().at(_currentSingleQuestionIndex).toString());
    ui->singleSelect4->setText(_singleQuestion["selection4"].toArray().at(_currentSingleQuestionIndex).toString());

}
//答题
void BrainStorm::singleAnswerQuestion(int select)
{
    if(select == _singleQuestion["answer"].toArray().at(_currentSingleQuestionIndex).toString().toInt())
    {
        _singleScore += 20*_singleSec;
        _currentSingleQuestionIndex++;
        singleSetQuestion(); //设置下一题
        _singleSec = 10;
        _singleTimer.stop();
        ui->lcdNumber->display(_singleSec);
        _singleTimer.start(1000);
    }
    else //回答错误
    {
        ui->singleResult->setText("回答错误");
        QString str = QString("本次得分: %1").arg(_singleScore);
        ui->singleScoreResult->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->singleScore);
        _singleTimer.stop();
    }

    //题目结束
    if(_currentSingleQuestionIndex == QUESTION_NUM)
    {
        ui->singleResult->setText("恭喜全部答对");
        QString str = QString("本次得分: %1").arg(_singleScore);
        ui->singleScoreResult->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->singleScore);
        _singleTimer.stop();
    }
}

//单人训练从服务接收题目
void BrainStorm::rcvSingleQuestion(QJsonObject json)
{
    _singleQuestion = json;
    _singleSec = 10;
    _currentSingleQuestionIndex = 0;
    _singleScore = 0;
    ui->lcdNumber->display(_singleSec);
    singleSetQuestion();

    //开启定时器
    _singleTimer.start(1000);
    ui->stackedWidget->setCurrentWidget(ui->singleRunning);
}

void BrainStorm::on_single_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}

//开始答题
void BrainStorm::on_single_start_clicked()
{
    singleGetQuestion();
}

void BrainStorm::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}

void BrainStorm::on_singleSelect1_clicked()
{
    singleAnswerQuestion(1);
}

void BrainStorm::on_singleSelect2_clicked()
{
    singleAnswerQuestion(2);
}

void BrainStorm::on_singleSelect3_clicked()
{
    singleAnswerQuestion(3);
}

void BrainStorm::on_singleSelect4_clicked()
{
    singleAnswerQuestion(4);
}

// -------------排位------------------
void BrainStorm::on_RankButton_clicked()
{
    QJsonObject json;
    json["cmd"] = RANK;

    _com->writeData(json);

    //跳转等待页面
    ui->stackedWidget->setCurrentWidget(ui->rank_wait);

}
void BrainStorm::rankTimerOut()
{
    _rankSec--;
    if(_rankSec == 0)
    {
        if(ui->rankSelect1->isEnabled())
        {
            _currentRankQuestionIndex++;
        }
        rankSetQuestion();
        _rankSec = 10;
    }
    ui->lcdNumber_2->display(_rankSec);
}

void BrainStorm::setEnemyStatus()
{
    QString str = QString("%1(%2): %3").arg(_enemyName, -5).arg(_enemyRank).arg(_enemyScore);
    ui->enemyStatus->setText(str);
}

void BrainStorm::setSelfStatus()
{
    QString str = QString("%1(%2): %3").arg(_userName, -5).arg(_userRank).arg(_myScore);
    ui->selfStatus->setText(str);
}

void BrainStorm::rankSetQuestion()
{
    ui->rankQuestion->setText(_rankQuestion["question"].toArray().at(_currentRankQuestionIndex).toString());
    ui->rankSelect1->setText(_rankQuestion["selection1"].toArray().at(_currentRankQuestionIndex).toString());
    ui->rankSelect2->setText(_rankQuestion["selection2"].toArray().at(_currentRankQuestionIndex).toString());
    ui->rankSelect3->setText(_rankQuestion["selection3"].toArray().at(_currentRankQuestionIndex).toString());
    ui->rankSelect4->setText(_rankQuestion["selection4"].toArray().at(_currentRankQuestionIndex).toString());

    ui->rankSelect1->setEnabled(true);
    ui->rankSelect2->setEnabled(true);
    ui->rankSelect3->setEnabled(true);
    ui->rankSelect4->setEnabled(true);

    ui->rankSelect1->setStyleSheet("");
    ui->rankSelect2->setStyleSheet("");
    ui->rankSelect3->setStyleSheet("");
    ui->rankSelect4->setStyleSheet("");

    if(_currentRankQuestionIndex == QUESTION_NUM)
    {
        _rankTimer.stop();
        //将结果发送给服务器

        QJsonObject json;
        json["cmd"] = RANKRESULT;
        json["score"] = _myScore;
        json["enemyName"] = _enemyName;
        json["enemyScore"] = _enemyScore;

        _com->writeData(json);
    }
}
void BrainStorm::rankAnswerQuestion(int select)
{
    //计算得分
    if(select == _rankQuestion["answer"].toArray().at(_currentRankQuestionIndex).toString().toInt())
    {
        _myScore += 20*_rankSec;
    }
    setSelfStatus();
    _currentRankQuestionIndex++;

    //判断是否跳到下一题
    if(_currentRankQuestionIndex == _enemyRankQuestionIndex)
    {
        _rankSec = 10;
        _rankTimer.stop();
        ui->lcdNumber_2->display(_rankSec);
        _rankTimer.start(1000);
        rankSetQuestion();
    }

    QJsonObject json;
    json["cmd"] = ANSWER;
    json["enemyName"] = _enemyName;
    json["score"] = _myScore;
    json["questionId"] = _currentRankQuestionIndex;

    _com->writeData(json);
}
void BrainStorm::Rank(QJsonObject json)
{
    //qDebug("--------------------");
    int cmd = json["cmd"].toInt();

    if(cmd == RANK)
    {
        _rankQuestion = json["question"].toObject();
        _enemyName = json["enemyName"].toString();
        _enemyRank = json["enemyRank"].toString();
        _enemyScore = json["enemyScore"].toInt();

        _rankSec = 10;
        _myScore = 0;
        _currentRankQuestionIndex = 0;
        _enemyRankQuestionIndex = 0;

        ui->lcdNumber_2->display(_rankSec);

        setEnemyStatus();
        setSelfStatus();
        rankSetQuestion();

        _rankTimer.start(1000);
        ui->stackedWidget->setCurrentWidget(ui->rank_running);
    }
    else if(cmd == ANSWER)
    {
        _enemyScore = json["enemyscore"].toInt();
        _enemyRankQuestionIndex = json["enemyQuestionId"].toInt();
        setEnemyStatus();

        if(_currentRankQuestionIndex == _enemyRankQuestionIndex)
        {
            _rankSec = 10;
            _rankTimer.stop();
            ui->lcdNumber_2->display(_rankSec);
            _rankTimer.start(1000);
            rankSetQuestion();
        }
    }
    else if(cmd == RANKRESULT)
    {
        rankSetResult(json);
    }
}

void BrainStorm::rankSetResult(QJsonObject &json)
{
    QString newRank = json["newRank"].toString();
    if(_myScore == _enemyScore)
    {
        ui->rankResult->setText("平局");
    }
    if(_myScore > _enemyScore)
    {
        ui->rankResult->setText("胜利");
    }
    if(_myScore < _enemyScore)
    {
        ui->rankResult->setText("失败");
    }
    QString str = QString("%1 ----> %2").arg(_userRank).arg(newRank);
    ui->Newrank->setText(str);
    _userRank = newRank;

    //------------------------

    QJsonObject newjson;
    newjson["cmd"] = UPDATE;
    //newjson["username"] = _userName;
    //newjson["myScore"] = _userRank;
    //qDebug("%s--------%s",qPrintable(_userName),qPrintable(_userRank));
    _com->writeData(newjson);

    ui->stackedWidget->setCurrentWidget(ui->rank_result);
}

void BrainStorm::on_rankSelect1_clicked()
{
    ui->rankSelect1->setStyleSheet("background-color: blue");
    ui->rankSelect1->setEnabled(false);
    ui->rankSelect2->setEnabled(false);
    ui->rankSelect3->setEnabled(false);
    ui->rankSelect4->setEnabled(false);

    rankAnswerQuestion(1);
}

void BrainStorm::on_rankSelect2_clicked()
{
    ui->rankSelect2->setStyleSheet("background-color: blue");
    ui->rankSelect1->setEnabled(false);
    ui->rankSelect2->setEnabled(false);
    ui->rankSelect3->setEnabled(false);
    ui->rankSelect4->setEnabled(false);

    rankAnswerQuestion(2);
}

void BrainStorm::on_rankSelect3_clicked()
{
    ui->rankSelect3->setStyleSheet("background-color: blue");
    ui->rankSelect1->setEnabled(false);
    ui->rankSelect2->setEnabled(false);
    ui->rankSelect3->setEnabled(false);
    ui->rankSelect4->setEnabled(false);

    rankAnswerQuestion(3);
}

void BrainStorm::on_rankSelect4_clicked()
{
    ui->rankSelect4->setStyleSheet("background-color: blue");
    ui->rankSelect1->setEnabled(false);
    ui->rankSelect2->setEnabled(false);
    ui->rankSelect3->setEnabled(false);
    ui->rankSelect4->setEnabled(false);

    rankAnswerQuestion(4);
}

void BrainStorm::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}
