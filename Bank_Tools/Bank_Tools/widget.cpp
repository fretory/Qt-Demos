#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include <QtDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("登录银行管理系统");
    ui->passline->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString name=ui->userline->text().trimmed();
    QString password=ui->passline->text().trimmed();
    if((name=="王涛")&&(password=="123456"))
    {
        qDebug()<<"登录成功";

        this->hide();
        func->show();
    }
    else {
        times+=1;
        if(times>=3)
        {
            QMessageBox::warning(this,"错误","已经错误三次，即将退出系统",QMessageBox::Ok);
            this->close();
            return;
        }
        QMessageBox::warning(this,"错误","账户或者密码错误",QMessageBox::Ok);
        ui->passline->clear();
        ui->userline->setFocus();
    }
}
