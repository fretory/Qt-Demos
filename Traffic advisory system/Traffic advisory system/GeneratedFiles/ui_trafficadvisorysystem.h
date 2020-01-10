/********************************************************************************
** Form generated from reading UI file 'trafficadvisorysystem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICADVISORYSYSTEM_H
#define UI_TRAFFICADVISORYSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrafficadvisorysystemClass
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableView *tableView;
    QPushButton *queryButton;
    QRadioButton *PriceradioButton;
    QRadioButton *TimeradioButton;
    QLabel *label_2;
    QLabel *trans;
    QLabel *start;
    QPushButton *select_01;
    QPushButton *select_02;
    QLabel *end;
    QComboBox *queryMode;
    QWidget *page_2;
    QTableView *tableView_2;
    QPushButton *delButton;
    QPushButton *saveButton;
    QLineEdit *lineEdit;
    QPushButton *changeButton;
    QPushButton *updateButton;
    QPushButton *addButton;
    QComboBox *typechoose;
    QTimeEdit *timeEdit;
    QLabel *label;
    QPushButton *eButton;
    QPushButton *qButton;
    QPushButton *minButton;
    QPushButton *closeButton;

    void setupUi(QWidget *TrafficadvisorysystemClass)
    {
        if (TrafficadvisorysystemClass->objectName().isEmpty())
            TrafficadvisorysystemClass->setObjectName(QStringLiteral("TrafficadvisorysystemClass"));
        TrafficadvisorysystemClass->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TrafficadvisorysystemClass->sizePolicy().hasHeightForWidth());
        TrafficadvisorysystemClass->setSizePolicy(sizePolicy);
        TrafficadvisorysystemClass->setMinimumSize(QSize(1000, 600));
        TrafficadvisorysystemClass->setMaximumSize(QSize(1000, 600));
        stackedWidget = new QStackedWidget(TrafficadvisorysystemClass);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(290, 120, 680, 460));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tableView = new QTableView(page);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 170, 631, 280));
        queryButton = new QPushButton(page);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(480, 62, 160, 60));
        PriceradioButton = new QRadioButton(page);
        PriceradioButton->setObjectName(QStringLiteral("PriceradioButton"));
        PriceradioButton->setGeometry(QRect(161, 50, 91, 16));
        QFont font;
        font.setPointSize(11);
        PriceradioButton->setFont(font);
        TimeradioButton = new QRadioButton(page);
        TimeradioButton->setObjectName(QStringLiteral("TimeradioButton"));
        TimeradioButton->setGeometry(QRect(242, 47, 141, 21));
        TimeradioButton->setFont(font);
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 111, 31));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        trans = new QLabel(page);
        trans->setObjectName(QStringLiteral("trans"));
        trans->setGeometry(QRect(231, 100, 60, 60));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(trans->sizePolicy().hasHeightForWidth());
        trans->setSizePolicy(sizePolicy1);
        start = new QLabel(page);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(61, 117, 72, 31));
        QFont font2;
        font2.setPointSize(13);
        start->setFont(font2);
        select_01 = new QPushButton(page);
        select_01->setObjectName(QStringLiteral("select_01"));
        select_01->setGeometry(QRect(141, 113, 75, 40));
        select_01->setFont(font);
        select_02 = new QPushButton(page);
        select_02->setObjectName(QStringLiteral("select_02"));
        select_02->setGeometry(QRect(391, 110, 75, 40));
        select_02->setFont(font);
        end = new QLabel(page);
        end->setObjectName(QStringLiteral("end"));
        end->setGeometry(QRect(321, 115, 72, 31));
        end->setFont(font2);
        queryMode = new QComboBox(page);
        queryMode->setObjectName(QStringLiteral("queryMode"));
        queryMode->setGeometry(QRect(390, 50, 87, 22));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tableView_2 = new QTableView(page_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(20, 20, 631, 351));
        delButton = new QPushButton(page_2);
        delButton->setObjectName(QStringLiteral("delButton"));
        delButton->setGeometry(QRect(119, 390, 90, 35));
        saveButton = new QPushButton(page_2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(563, 390, 90, 35));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(221, 390, 130, 35));
        changeButton = new QPushButton(page_2);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(362, 390, 90, 35));
        updateButton = new QPushButton(page_2);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(20, 390, 90, 35));
        addButton = new QPushButton(page_2);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(461, 390, 90, 35));
        typechoose = new QComboBox(page_2);
        typechoose->setObjectName(QStringLiteral("typechoose"));
        typechoose->setGeometry(QRect(220, 390, 130, 35));
        timeEdit = new QTimeEdit(page_2);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(220, 390, 130, 35));
        stackedWidget->addWidget(page_2);
        label = new QLabel(TrafficadvisorysystemClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 671, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Cascadia Code"));
        font3.setPointSize(26);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        eButton = new QPushButton(TrafficadvisorysystemClass);
        eButton->setObjectName(QStringLiteral("eButton"));
        eButton->setGeometry(QRect(80, 390, 160, 60));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(eButton->sizePolicy().hasHeightForWidth());
        eButton->setSizePolicy(sizePolicy2);
        qButton = new QPushButton(TrafficadvisorysystemClass);
        qButton->setObjectName(QStringLiteral("qButton"));
        qButton->setGeometry(QRect(80, 290, 160, 60));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(qButton->sizePolicy().hasHeightForWidth());
        qButton->setSizePolicy(sizePolicy3);
        minButton = new QPushButton(TrafficadvisorysystemClass);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(890, 20, 25, 25));
        closeButton = new QPushButton(TrafficadvisorysystemClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(960, 20, 25, 25));

        retranslateUi(TrafficadvisorysystemClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TrafficadvisorysystemClass);
    } // setupUi

    void retranslateUi(QWidget *TrafficadvisorysystemClass)
    {
        TrafficadvisorysystemClass->setWindowTitle(QApplication::translate("TrafficadvisorysystemClass", "Trafficadvisorysystem", 0));
        queryButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Query", 0));
        PriceradioButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Price", 0));
        TimeradioButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Time Costing", 0));
        label_2->setText(QApplication::translate("TrafficadvisorysystemClass", "Strategy", 0));
        trans->setText(QApplication::translate("TrafficadvisorysystemClass", "TextLabel", 0));
        start->setText(QApplication::translate("TrafficadvisorysystemClass", "start", 0));
        select_01->setText(QApplication::translate("TrafficadvisorysystemClass", "select", 0));
        select_02->setText(QApplication::translate("TrafficadvisorysystemClass", "select", 0));
        end->setText(QApplication::translate("TrafficadvisorysystemClass", "end", 0));
        queryMode->clear();
        queryMode->insertItems(0, QStringList()
         << QApplication::translate("TrafficadvisorysystemClass", "Train", 0)
         << QApplication::translate("TrafficadvisorysystemClass", "Plane", 0)
        );
        delButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Delete", 0));
        saveButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Save", 0));
        changeButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Change", 0));
        updateButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Update", 0));
        addButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Add", 0));
        typechoose->clear();
        typechoose->insertItems(0, QStringList()
         << QApplication::translate("TrafficadvisorysystemClass", "train", 0)
         << QApplication::translate("TrafficadvisorysystemClass", "plane", 0)
        );
        label->setText(QApplication::translate("TrafficadvisorysystemClass", "Traffic Advisory System", 0));
        eButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Edit", 0));
        qButton->setText(QApplication::translate("TrafficadvisorysystemClass", "Query", 0));
        minButton->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrafficadvisorysystemClass: public Ui_TrafficadvisorysystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICADVISORYSYSTEM_H
