#include "funcdialog.h"
#include "ui_funcdialog.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QVariantList>
#include <QMessageBox>
#include <QDateTime>
#include <QSqlTableModel>
#include <QSqlRecord>

FuncDialog::FuncDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FuncDialog)
{
    /*
     * 设置界面的各种背景颜色
     * 并且将stackedWidget定位到第三面(欢迎界面)
     * 初始化各种控件的颜色
     */

    ui->setupUi(this);
    setWindowTitle("个人银行管理系统");
    //setStyleSheet("background-color:#36d2ff");//整体颜色
    ui->welocme->setStyleSheet("color:pink");//设置字体颜色
    ui->stackedWidget->setCurrentIndex(2);//提示用户选择模式按钮
    ui->TOTAL->setCurrentIndex(2);//欢迎页面
    inittable();





}

FuncDialog::~FuncDialog()
{
    delete ui;
}

void FuncDialog::on_cardbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->TOTAL->setCurrentIndex(2);
}

void FuncDialog::on_creditbutoon_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->TOTAL->setCurrentIndex(2);
}

void FuncDialog::on_storage_button1_clicked()
{
    ui->TOTAL->setCurrentIndex(0);
    ui->storage_func->setCurrentIndex(0);


}

/*
 * 事件:点击账户一览表
 * 功能:显示所有的账户
 * 编写:王涛
 * 实现:sqlite数据库
 */

void FuncDialog::on_storage_button2_clicked()
{
    ui->TOTAL->setCurrentIndex(0);
    ui->storage_func->setCurrentIndex(1);

}

void FuncDialog::inittable()
{
    //添加数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("../info.db");

    if(!db.open())//如果打开数据库失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    //设置模型
    model = new QSqlTableModel(this);
    //指定使用哪个表
    model->setTable("CardInfo");

    //把model放到view
    //view中的数据库不允许修改
    ui->InfoBalance->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->InfoBalance->setModel(model);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"卡号");
    model->setHeaderData(1,Qt::Horizontal,"余额");
    model->setHeaderData(2,Qt::Horizontal,"利率");
    model->setHeaderData(3,Qt::Horizontal,"上次结息日期");
}
void FuncDialog::on_credit_button_clicked()
{

}

void FuncDialog::on_credit_button_3_clicked()
{

}

void FuncDialog::on_comboBox_currentIndexChanged(int index)
{
    //上来先关闭一手连接
    //以免被占用,报错不显示
    QSqlDatabase::removeDatabase("change");
    QString cardid;
    switch (index) {
    case 1:cardid="c_445989";break;
    case 2:cardid="c_467149";break;
    case 3:cardid="c_498138";break;
    case 4:cardid="c_440410";break;
    case 5:cardid="c_455086";break;
    default:return;
    }


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","change");


    db.setDatabaseName("../info.db");

    if(!db.open())//如果打开数据库失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    //设置模型
    typical = new QSqlTableModel(this);
    //指定使用哪个表
    typical->setTable(cardid);

    //把model放到view
    //view中的数据库不允许修改
    ui->waterBalance->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->waterBalance->setModel(typical);
    ui->waterBalance->verticalHeader()->hide();
    typical->select();
    typical->setHeaderData(0,Qt::Horizontal,"流水号");
    typical->setHeaderData(1,Qt::Horizontal,"类型");
    typical->setHeaderData(2,Qt::Horizontal,"变化金额");
    typical->setHeaderData(3,Qt::Horizontal,"余额");
    typical->setHeaderData(4,Qt::Horizontal,"结算日期");


}

void FuncDialog::on_submitn_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        QMessageBox::warning(this,"Error","请选择卡号");
        return;
    }
    if(ui->changesline->text().isEmpty())
    {
        QMessageBox::warning(this,"Error","请输入金额");
        return;
    }
    if(ui->types->currentIndex()==0)
    {
        QMessageBox::warning(this,"Error","请选择类型");
        return;
    }


            QString cardid;
            switch (ui->comboBox->currentIndex()) {
            case 1:cardid="c_445989";break;
            case 2:cardid="c_467149";break;
            case 3:cardid="c_498138";break;
            case 4:cardid="c_440410";break;
            case 5:cardid="c_455086";break;
            default:return;
            }
    QSqlDatabase::removeDatabase("edit");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","edit");


    db.setDatabaseName("../info.db");

    if(!db.open())//如果打开数据库失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }

    float last=0;//记录最后一次的余额
    QSqlQuery temp;
    temp.exec(QString("select * from %1").arg(cardid));
    int id=0;
    while(temp.next())
    {
        id=temp.value(0).toInt();
        last=temp.value(3).toFloat();
    }

    id+=1;


    QString Outtype;
    //获取日期
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strtime = time.toString("yyyy-MM-dd");

    //改变后的余额
    if(ui->types->currentIndex()==1)
    {
        last+=ui->changesline->text().toFloat();
        Outtype="收入";
    }
    else if(ui->types->currentIndex()==2)
    {
        last-=ui->changesline->text().toFloat();
        Outtype="支出";
    }

    QSqlQuery query;    //用于执行sql语句的对象
    QString s=QString("INSERT INTO %1 VALUES (%2, '%3', %4,%5, '%6' )").arg(cardid).arg(id).arg(Outtype).
            arg(ui->changesline->text()).arg(last).arg(strtime);
    query.exec(s);
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}
