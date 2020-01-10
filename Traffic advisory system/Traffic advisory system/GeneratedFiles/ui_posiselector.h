/********************************************************************************
** Form generated from reading UI file 'posiselector.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSISELECTOR_H
#define UI_POSISELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PosiSelector
{
public:
    QTableWidget *qtablewidget;

    void setupUi(QWidget *PosiSelector)
    {
        if (PosiSelector->objectName().isEmpty())
            PosiSelector->setObjectName(QStringLiteral("PosiSelector"));
        PosiSelector->resize(116, 120);
        qtablewidget = new QTableWidget(PosiSelector);
        if (qtablewidget->columnCount() < 3)
            qtablewidget->setColumnCount(3);
        qtablewidget->setObjectName(QStringLiteral("qtablewidget"));
        qtablewidget->setGeometry(QRect(0, 0, 90, 120));
        qtablewidget->setColumnCount(3);

        retranslateUi(PosiSelector);

        QMetaObject::connectSlotsByName(PosiSelector);
    } // setupUi

    void retranslateUi(QWidget *PosiSelector)
    {
        PosiSelector->setWindowTitle(QApplication::translate("PosiSelector", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PosiSelector: public Ui_PosiSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSISELECTOR_H
