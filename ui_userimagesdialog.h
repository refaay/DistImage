/********************************************************************************
** Form generated from reading UI file 'userimagesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERIMAGESDIALOG_H
#define UI_USERIMAGESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_userimagesdialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_us;
    QSpacerItem *horizontalSpacer;
    QPushButton *push_back;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *push_request;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *line_views;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_result;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_time;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *userimagesdialog)
    {
        if (userimagesdialog->objectName().isEmpty())
            userimagesdialog->setObjectName(QStringLiteral("userimagesdialog"));
        userimagesdialog->resize(500, 500);
        userimagesdialog->setStyleSheet(QLatin1String("background-color: rgb(46, 52, 54)\n"
""));
        verticalLayout = new QVBoxLayout(userimagesdialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbl_us = new QLabel(userimagesdialog);
        lbl_us->setObjectName(QStringLiteral("lbl_us"));
        lbl_us->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        horizontalLayout_2->addWidget(lbl_us);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        push_back = new QPushButton(userimagesdialog);
        push_back->setObjectName(QStringLiteral("push_back"));
        push_back->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        horizontalLayout_2->addWidget(push_back);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(userimagesdialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(userimagesdialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        push_request = new QPushButton(userimagesdialog);
        push_request->setObjectName(QStringLiteral("push_request"));
        push_request->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        horizontalLayout->addWidget(push_request);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        line_views = new QLineEdit(userimagesdialog);
        line_views->setObjectName(QStringLiteral("line_views"));
        line_views->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        horizontalLayout->addWidget(line_views);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_result = new QLabel(userimagesdialog);
        lbl_result->setObjectName(QStringLiteral("lbl_result"));

        horizontalLayout_3->addWidget(lbl_result);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbl_time = new QLabel(userimagesdialog);
        lbl_time->setObjectName(QStringLiteral("lbl_time"));
        lbl_time->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236)"));

        horizontalLayout_7->addWidget(lbl_time);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_7);

        QWidget::setTabOrder(listWidget, push_back);

        retranslateUi(userimagesdialog);
        QObject::connect(push_back, SIGNAL(clicked()), userimagesdialog, SLOT(close()));

        QMetaObject::connectSlotsByName(userimagesdialog);
    } // setupUi

    void retranslateUi(QDialog *userimagesdialog)
    {
        userimagesdialog->setWindowTitle(QApplication::translate("userimagesdialog", "DistImage", nullptr));
        lbl_us->setText(QApplication::translate("userimagesdialog", "User", nullptr));
        push_back->setText(QApplication::translate("userimagesdialog", "Back", nullptr));
        label->setText(QApplication::translate("userimagesdialog", "Images:", nullptr));
        push_request->setText(QApplication::translate("userimagesdialog", "Request", nullptr));
        line_views->setText(QString());
        lbl_result->setText(QApplication::translate("userimagesdialog", "Request Done", nullptr));
        lbl_time->setText(QApplication::translate("userimagesdialog", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userimagesdialog: public Ui_userimagesdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERIMAGESDIALOG_H
