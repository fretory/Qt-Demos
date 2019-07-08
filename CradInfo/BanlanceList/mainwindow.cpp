#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QVariantList>
#include <QMessageBox>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->InfoBalance->verticalHeader()->hide();
    ui->InfoBalance->setEditTriggers(QAbstractItemView::NoEditTriggers);
    init();
    ui->InfoBalance->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
    ui->dateEdit->setMinimumDate(QDate::fromString("2016/6","yyyy/M"));
    setui();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains())
        db = QSqlDatabase::database();
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
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
    model->sort(0,Qt::SortOrder::DescendingOrder);
    //把model放到view
    //view中的数据库不允许修改
    ui->InfoBalance->setModel(model);
    model->select();
}

void MainWindow::on_pushButton_4_clicked()
{
    QDate last=QDate::currentDate().addDays(-7);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));
    if(!ui->InfoBalance->verticalHeader()->count())
    {
        QMessageBox::warning(this,"暂无消费","最近7天您还没有消费哦~");
        model->setTable("CardInfo");
        setui();
        model->sort(0,Qt::SortOrder::DescendingOrder);
        model->select();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QDate last=QDate::currentDate().addMonths(-1);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));
    if(!ui->InfoBalance->verticalHeader()->count())
    {
        QMessageBox::warning(this,"暂无消费","最近1个月您还没有消费哦~");
        model->setTable("CardInfo");
        setui();
        model->sort(0,Qt::SortOrder::DescendingOrder);
        model->select();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QDate last=QDate::currentDate().addMonths(-3);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));
    if(!ui->InfoBalance->verticalHeader()->count())
    {
        QMessageBox::warning(this,"暂无消费","最近3个月您还没有消费哦~");
        model->setTable("CardInfo");
        setui();
        model->sort(0,Qt::SortOrder::DescendingOrder);
        model->select();
    }
}

void MainWindow::setui()
{
    model->setHeaderData(0,Qt::Horizontal,"流水号");
    model->setHeaderData(1,Qt::Horizontal,"类型");
    model->setHeaderData(2,Qt::Horizontal,"变化金额");
    model->setHeaderData(3,Qt::Horizontal,"余额");
    model->setHeaderData(4,Qt::Horizontal,"结算日期");
}

void MainWindow::on_pushButton_6_clicked()
{
    model->setTable("CardInfo");
    setui();
    model->sort(0,Qt::SortOrder::DescendingOrder);
    model->select();
}

void MainWindow::on_pushButton_clicked()
{
    QString str=ui->dateEdit->text();
    QDate lefttime;
    QDate righttime;
    str=str.trimmed();
    if (!str.isEmpty())
    {
        lefttime=QDate::fromString(str,"yyyy/M");
    }
    righttime=lefttime.addMonths(1);

    model->setFilter(QObject::tr("DATETIME > '%0' AND DATETIME < '%1'").arg(lefttime.toString("yyyy-MM-dd")).arg(righttime.toString("yyyy-MM-dd")));
    if(!ui->InfoBalance->verticalHeader()->count())
    {
        QMessageBox::warning(this,"暂无消费",QString("在%1，您还没有消费哦~").arg(lefttime.toString("yyyy年MM月")));

        model->setTable("CardInfo");
        setui();
        model->sort(0,Qt::SortOrder::DescendingOrder);
        model->select();
    }
}
