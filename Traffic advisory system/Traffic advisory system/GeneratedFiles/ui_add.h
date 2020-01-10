/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ADDITEM
{
public:
    QTimeEdit *timeEdit;
    QTimeEdit *timeEdit_2;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *uuid;
    QLabel *label_6;
    QLineEdit *price;
    QPushButton *submmit;
    QPushButton *cancel;
    QPushButton *add_station;
    QLabel *start;
    QLabel *terminal;
    QPushButton *addstart;
    QPushButton *addterminal;
    QLineEdit *station_name;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *distance;

    void setupUi(QWidget *ADDITEM)
    {
        if (ADDITEM->objectName().isEmpty())
            ADDITEM->setObjectName(QStringLiteral("ADDITEM"));
        ADDITEM->setWindowModality(Qt::WindowModal);
        ADDITEM->resize(780, 163);
        ADDITEM->setWindowOpacity(1);
        timeEdit = new QTimeEdit(ADDITEM);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(450, 47, 118, 22));
        timeEdit_2 = new QTimeEdit(ADDITEM);
        timeEdit_2->setObjectName(QStringLiteral("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(310, 47, 118, 22));
        comboBox = new QComboBox(ADDITEM);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(334, 95, 87, 22));
        label = new QLabel(ADDITEM);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 27, 121, 20));
        label_2 = new QLabel(ADDITEM);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(188, 27, 72, 15));
        label_3 = new QLabel(ADDITEM);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(311, 27, 121, 20));
        label_4 = new QLabel(ADDITEM);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(469, 27, 72, 15));
        label_5 = new QLabel(ADDITEM);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(94, 77, 72, 15));
        uuid = new QLineEdit(ADDITEM);
        uuid->setObjectName(QStringLiteral("uuid"));
        uuid->setGeometry(QRect(74, 97, 113, 21));
        label_6 = new QLabel(ADDITEM);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(474, 77, 72, 15));
        price = new QLineEdit(ADDITEM);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(450, 97, 113, 21));
        price->setInputMethodHints(Qt::ImhPreferNumbers);
        price->setEchoMode(QLineEdit::Normal);
        submmit = new QPushButton(ADDITEM);
        submmit->setObjectName(QStringLiteral("submmit"));
        submmit->setGeometry(QRect(620, 10, 131, 40));
        cancel = new QPushButton(ADDITEM);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(620, 60, 131, 40));
        add_station = new QPushButton(ADDITEM);
        add_station->setObjectName(QStringLiteral("add_station"));
        add_station->setGeometry(QRect(620, 110, 131, 40));
        start = new QLabel(ADDITEM);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(25, 47, 100, 22));
        terminal = new QLabel(ADDITEM);
        terminal->setObjectName(QStringLiteral("terminal"));
        terminal->setGeometry(QRect(176, 47, 91, 22));
        addstart = new QPushButton(ADDITEM);
        addstart->setObjectName(QStringLiteral("addstart"));
        addstart->setGeometry(QRect(120, 47, 25, 25));
        addterminal = new QPushButton(ADDITEM);
        addterminal->setObjectName(QStringLiteral("addterminal"));
        addterminal->setGeometry(QRect(270, 47, 25, 25));
        station_name = new QLineEdit(ADDITEM);
        station_name->setObjectName(QStringLiteral("station_name"));
        station_name->setGeometry(QRect(320, 130, 161, 21));
        station_name->setInputMethodHints(Qt::ImhPreferNumbers);
        station_name->setEchoMode(QLineEdit::Normal);
        label_7 = new QLabel(ADDITEM);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 130, 121, 20));
        label_8 = new QLabel(ADDITEM);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(224, 76, 72, 15));
        distance = new QLineEdit(ADDITEM);
        distance->setObjectName(QStringLiteral("distance"));
        distance->setGeometry(QRect(200, 96, 113, 21));
        distance->setInputMethodHints(Qt::ImhPreferNumbers);
        distance->setEchoMode(QLineEdit::Normal);

        retranslateUi(ADDITEM);

        QMetaObject::connectSlotsByName(ADDITEM);
    } // setupUi

    void retranslateUi(QWidget *ADDITEM)
    {
        ADDITEM->setWindowTitle(QApplication::translate("ADDITEM", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ADDITEM", "train", 0)
         << QApplication::translate("ADDITEM", "plane", 0)
        );
        label->setText(QApplication::translate("ADDITEM", "start/station", 0));
        label_2->setText(QApplication::translate("ADDITEM", "terminal", 0));
        label_3->setText(QApplication::translate("ADDITEM", "departure time", 0));
        label_4->setText(QApplication::translate("ADDITEM", "time cost", 0));
        label_5->setText(QApplication::translate("ADDITEM", "uuid", 0));
        label_6->setText(QApplication::translate("ADDITEM", "price", 0));
        submmit->setText(QApplication::translate("ADDITEM", "Submmit", 0));
        cancel->setText(QApplication::translate("ADDITEM", "Cancel", 0));
        add_station->setText(QApplication::translate("ADDITEM", "Add Station", 0));
        start->setText(QString());
        terminal->setText(QString());
        addstart->setText(QString());
        addterminal->setText(QString());
        label_7->setText(QApplication::translate("ADDITEM", "Station Name", 0));
        label_8->setText(QApplication::translate("ADDITEM", "distance", 0));
    } // retranslateUi

};

namespace Ui {
    class ADDITEM: public Ui_ADDITEM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
