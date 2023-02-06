/********************************************************************************
** Form generated from reading UI file 'brainstorm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAINSTORM_H
#define UI_BRAINSTORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrainStorm
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QGridLayout *gridLayout_2;
    QPushButton *RankButton;
    QPushButton *SingleTrainButton;
    QWidget *singleMenu;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *single_start;
    QPushButton *single_back;
    QWidget *singleRunning;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *singleQuestion;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *singleSelect1;
    QPushButton *singleSelect2;
    QPushButton *singleSelect3;
    QPushButton *singleSelect4;
    QWidget *singleScore;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *singleResult;
    QSpacerItem *verticalSpacer_4;
    QLabel *singleScoreResult;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_2;
    QWidget *rank_wait;
    QLabel *label_3;
    QWidget *rank_running;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *enemyStatus;
    QLabel *selfStatus;
    QLCDNumber *lcdNumber_2;
    QLabel *rankQuestion;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *rankSelect1;
    QPushButton *rankSelect2;
    QPushButton *rankSelect3;
    QPushButton *rankSelect4;
    QWidget *rank_result;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_8;
    QLabel *rankResult;
    QLabel *Newrank;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton;

    void setupUi(QDialog *BrainStorm)
    {
        if (BrainStorm->objectName().isEmpty())
            BrainStorm->setObjectName(QStringLiteral("BrainStorm"));
        BrainStorm->resize(335, 592);
        verticalLayout_3 = new QVBoxLayout(BrainStorm);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stackedWidget = new QStackedWidget(BrainStorm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        stackedWidget->setFont(font);
        mainMenu = new QWidget();
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        gridLayout_2 = new QGridLayout(mainMenu);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        RankButton = new QPushButton(mainMenu);
        RankButton->setObjectName(QStringLiteral("RankButton"));
        RankButton->setMaximumSize(QSize(200, 40));

        gridLayout_2->addWidget(RankButton, 0, 0, 1, 1);

        SingleTrainButton = new QPushButton(mainMenu);
        SingleTrainButton->setObjectName(QStringLiteral("SingleTrainButton"));
        SingleTrainButton->setMaximumSize(QSize(200, 40));

        gridLayout_2->addWidget(SingleTrainButton, 1, 0, 1, 1);

        stackedWidget->addWidget(mainMenu);
        singleMenu = new QWidget();
        singleMenu->setObjectName(QStringLiteral("singleMenu"));
        verticalLayout_2 = new QVBoxLayout(singleMenu);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(singleMenu);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(28);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(singleMenu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        single_start = new QPushButton(singleMenu);
        single_start->setObjectName(QStringLiteral("single_start"));

        verticalLayout_2->addWidget(single_start);

        single_back = new QPushButton(singleMenu);
        single_back->setObjectName(QStringLiteral("single_back"));

        verticalLayout_2->addWidget(single_back);

        stackedWidget->addWidget(singleMenu);
        singleRunning = new QWidget();
        singleRunning->setObjectName(QStringLiteral("singleRunning"));
        verticalLayout_4 = new QVBoxLayout(singleRunning);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_2 = new QWidget(singleRunning);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 100));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lcdNumber = new QLCDNumber(widget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMaximumSize(QSize(100, 50));
        QFont font2;
        font2.setPointSize(26);
        lcdNumber->setFont(font2);

        gridLayout->addWidget(lcdNumber, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widget_2);

        singleQuestion = new QLabel(singleRunning);
        singleQuestion->setObjectName(QStringLiteral("singleQuestion"));
        QFont font3;
        font3.setPointSize(14);
        singleQuestion->setFont(font3);
        singleQuestion->setAlignment(Qt::AlignCenter);
        singleQuestion->setWordWrap(true);

        verticalLayout_4->addWidget(singleQuestion);

        widget = new QWidget(singleRunning);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        singleSelect1 = new QPushButton(widget);
        singleSelect1->setObjectName(QStringLiteral("singleSelect1"));

        verticalLayout->addWidget(singleSelect1);

        singleSelect2 = new QPushButton(widget);
        singleSelect2->setObjectName(QStringLiteral("singleSelect2"));

        verticalLayout->addWidget(singleSelect2);

        singleSelect3 = new QPushButton(widget);
        singleSelect3->setObjectName(QStringLiteral("singleSelect3"));

        verticalLayout->addWidget(singleSelect3);

        singleSelect4 = new QPushButton(widget);
        singleSelect4->setObjectName(QStringLiteral("singleSelect4"));

        verticalLayout->addWidget(singleSelect4);


        verticalLayout_4->addWidget(widget);

        stackedWidget->addWidget(singleRunning);
        singleScore = new QWidget();
        singleScore->setObjectName(QStringLiteral("singleScore"));
        verticalLayout_5 = new QVBoxLayout(singleScore);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        singleResult = new QLabel(singleScore);
        singleResult->setObjectName(QStringLiteral("singleResult"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(22);
        singleResult->setFont(font4);
        singleResult->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(singleResult);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        singleScoreResult = new QLabel(singleScore);
        singleScoreResult->setObjectName(QStringLiteral("singleScoreResult"));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(18);
        singleScoreResult->setFont(font5);
        singleScoreResult->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(singleScoreResult);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        pushButton_2 = new QPushButton(singleScore);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);

        stackedWidget->addWidget(singleScore);
        rank_wait = new QWidget();
        rank_wait->setObjectName(QStringLiteral("rank_wait"));
        label_3 = new QLabel(rank_wait);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 241, 101));
        QFont font6;
        font6.setPointSize(22);
        label_3->setFont(font6);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(rank_wait);
        rank_running = new QWidget();
        rank_running->setObjectName(QStringLiteral("rank_running"));
        verticalLayout_8 = new QVBoxLayout(rank_running);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        widget_5 = new QWidget(rank_running);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMaximumSize(QSize(16777215, 100));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_7 = new QVBoxLayout(widget_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        enemyStatus = new QLabel(widget_4);
        enemyStatus->setObjectName(QStringLiteral("enemyStatus"));

        verticalLayout_7->addWidget(enemyStatus);

        selfStatus = new QLabel(widget_4);
        selfStatus->setObjectName(QStringLiteral("selfStatus"));

        verticalLayout_7->addWidget(selfStatus);


        horizontalLayout->addWidget(widget_4);

        lcdNumber_2 = new QLCDNumber(widget_5);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        QFont font7;
        font7.setPointSize(16);
        lcdNumber_2->setFont(font7);

        horizontalLayout->addWidget(lcdNumber_2);


        verticalLayout_8->addWidget(widget_5);

        rankQuestion = new QLabel(rank_running);
        rankQuestion->setObjectName(QStringLiteral("rankQuestion"));
        QFont font8;
        font8.setPointSize(20);
        rankQuestion->setFont(font8);
        rankQuestion->setAlignment(Qt::AlignCenter);
        rankQuestion->setWordWrap(true);

        verticalLayout_8->addWidget(rankQuestion);

        widget_3 = new QWidget(rank_running);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        rankSelect1 = new QPushButton(widget_3);
        rankSelect1->setObjectName(QStringLiteral("rankSelect1"));

        verticalLayout_6->addWidget(rankSelect1);

        rankSelect2 = new QPushButton(widget_3);
        rankSelect2->setObjectName(QStringLiteral("rankSelect2"));

        verticalLayout_6->addWidget(rankSelect2);

        rankSelect3 = new QPushButton(widget_3);
        rankSelect3->setObjectName(QStringLiteral("rankSelect3"));

        verticalLayout_6->addWidget(rankSelect3);

        rankSelect4 = new QPushButton(widget_3);
        rankSelect4->setObjectName(QStringLiteral("rankSelect4"));

        verticalLayout_6->addWidget(rankSelect4);


        verticalLayout_8->addWidget(widget_3);

        stackedWidget->addWidget(rank_running);
        rank_result = new QWidget();
        rank_result->setObjectName(QStringLiteral("rank_result"));
        verticalLayout_9 = new QVBoxLayout(rank_result);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_8);

        rankResult = new QLabel(rank_result);
        rankResult->setObjectName(QStringLiteral("rankResult"));
        rankResult->setFont(font2);
        rankResult->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(rankResult);

        Newrank = new QLabel(rank_result);
        Newrank->setObjectName(QStringLiteral("Newrank"));
        Newrank->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(Newrank);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        pushButton = new QPushButton(rank_result);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_9->addWidget(pushButton);

        stackedWidget->addWidget(rank_result);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(BrainStorm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BrainStorm);
    } // setupUi

    void retranslateUi(QDialog *BrainStorm)
    {
        BrainStorm->setWindowTitle(QApplication::translate("BrainStorm", "Dialog", Q_NULLPTR));
        RankButton->setText(QApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", Q_NULLPTR));
        SingleTrainButton->setText(QApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203\350\265\233", Q_NULLPTR));
        label->setText(QApplication::translate("BrainStorm", "\350\277\236\347\273\255\347\255\224\345\257\2715\351\201\223\351\242\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("BrainStorm", "\347\255\224\351\224\231\347\246\273\345\234\272\357\274\214\347\255\224\345\257\271\347\273\247\347\273\255", Q_NULLPTR));
        single_start->setText(QApplication::translate("BrainStorm", "\345\274\200\345\247\213\347\255\224\351\242\230", Q_NULLPTR));
        single_back->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        singleQuestion->setText(QApplication::translate("BrainStorm", "A", Q_NULLPTR));
        singleSelect1->setText(QString());
        singleSelect2->setText(QString());
        singleSelect3->setText(QString());
        singleSelect4->setText(QString());
        singleResult->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        singleScoreResult->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        label_3->setText(QApplication::translate("BrainStorm", "\346\255\243\345\234\250\345\214\271\351\205\215\345\257\271\346\211\213....", Q_NULLPTR));
        enemyStatus->setText(QApplication::translate("BrainStorm", "\345\260\217\346\230\216  \351\273\204\351\207\2211 1\351\242\227\346\230\237:120\345\210\206", Q_NULLPTR));
        selfStatus->setText(QApplication::translate("BrainStorm", "\345\260\217\346\230\216  \347\231\275\351\223\2663 3\351\242\227\346\230\237:140\345\210\206", Q_NULLPTR));
        rankQuestion->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        rankSelect1->setText(QApplication::translate("BrainStorm", "1", Q_NULLPTR));
        rankSelect2->setText(QApplication::translate("BrainStorm", "2", Q_NULLPTR));
        rankSelect3->setText(QApplication::translate("BrainStorm", "3", Q_NULLPTR));
        rankSelect4->setText(QApplication::translate("BrainStorm", "4", Q_NULLPTR));
        rankResult->setText(QApplication::translate("BrainStorm", "\350\203\234\345\210\251", Q_NULLPTR));
        Newrank->setText(QApplication::translate("BrainStorm", "\351\273\204\351\207\2211  2\351\242\227\346\230\237 ---> \351\273\204\351\207\2211  3\351\242\227\346\230\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrainStorm: public Ui_BrainStorm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAINSTORM_H
