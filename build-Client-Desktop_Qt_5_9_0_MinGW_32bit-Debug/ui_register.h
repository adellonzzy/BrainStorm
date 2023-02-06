/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *UserNamelineEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *PWlineEdit;
    QPushButton *sign_up;
    QPushButton *go_back;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(444, 339);
        gridLayout = new QGridLayout(Register);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        widget_3 = new QWidget(Register);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        UserNamelineEdit = new QLineEdit(widget);
        UserNamelineEdit->setObjectName(QStringLiteral("UserNamelineEdit"));
        UserNamelineEdit->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(UserNamelineEdit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        PWlineEdit = new QLineEdit(widget_2);
        PWlineEdit->setObjectName(QStringLiteral("PWlineEdit"));
        PWlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PWlineEdit);


        verticalLayout->addWidget(widget_2);

        sign_up = new QPushButton(widget_3);
        sign_up->setObjectName(QStringLiteral("sign_up"));

        verticalLayout->addWidget(sign_up, 0, Qt::AlignHCenter);

        go_back = new QPushButton(widget_3);
        go_back->setObjectName(QStringLiteral("go_back"));

        verticalLayout->addWidget(go_back, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addWidget(widget_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206  \347\240\201", Q_NULLPTR));
        sign_up->setText(QApplication::translate("Register", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        go_back->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
