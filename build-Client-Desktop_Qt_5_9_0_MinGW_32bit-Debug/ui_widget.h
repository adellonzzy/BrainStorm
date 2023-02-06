/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *UserNamelineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *PWlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sign_in;
    QPushButton *sign_up;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(424, 281);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        UserNamelineEdit = new QLineEdit(widget);
        UserNamelineEdit->setObjectName(QStringLiteral("UserNamelineEdit"));

        horizontalLayout->addWidget(UserNamelineEdit);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        PWlineEdit = new QLineEdit(widget);
        PWlineEdit->setObjectName(QStringLiteral("PWlineEdit"));
        PWlineEdit->setMaximumSize(QSize(16777215, 16777215));
        PWlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PWlineEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sign_in = new QPushButton(widget);
        sign_in->setObjectName(QStringLiteral("sign_in"));

        horizontalLayout_3->addWidget(sign_in);

        sign_up = new QPushButton(widget);
        sign_up->setObjectName(QStringLiteral("sign_up"));

        horizontalLayout_3->addWidget(sign_up);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        widget->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        UserNamelineEdit->setText(QApplication::translate("Widget", "root", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\257\206  \347\240\201", Q_NULLPTR));
        PWlineEdit->setText(QApplication::translate("Widget", "123456", Q_NULLPTR));
        sign_in->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        sign_up->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
