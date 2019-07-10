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
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include<QPrintPreviewDialog>
#include<QPainter>
#include<QStandardPaths>
#include<QTextDocument>
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

    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
    ui->lineEdit->setValidator(validator);
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
    //把model放到view
    //view中的数据库不允许修改
    ui->InfoBalance->setModel(model);
    model->select();
    Get_Pages();
    RecordQuery(0);
    Update_Status();

}

void MainWindow::on_pushButton_4_clicked()
{
    QDate last=QDate::currentDate().addDays(-7);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));

    if(!ui->InfoBalance->verticalHeader()->count())
    {
        ui->Current_Pages->setHidden(true);
        ui->All_Pages->setHidden(true);
        QMessageBox::warning(this,"暂无消费","最近7天您还没有消费哦~");
        on_pushButton_6_clicked();
    }
    Get_Pages();
    RecordQuery(0);
    Update_Status();
}

void MainWindow::on_pushButton_3_clicked()
{
    QDate last=QDate::currentDate().addMonths(-1);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));

    if(!ui->InfoBalance->verticalHeader()->count())
    {
        ui->Current_Pages->setHidden(true);
        ui->All_Pages->setHidden(true);
        QMessageBox::warning(this,"暂无消费","最近1个月您还没有消费哦~");
        on_pushButton_6_clicked();
    }
    RecordQuery(0);
    Get_Pages();
    Update_Status();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDate last=QDate::currentDate().addMonths(-3);
    model->setFilter(QObject::tr("DATETIME > '%1'").arg(last.toString("yyyy-MM-dd")));
    if(!ui->InfoBalance->verticalHeader()->count())
    {
        ui->Current_Pages->setHidden(true);
        ui->All_Pages->setHidden(true);
        QMessageBox::warning(this,"暂无消费","最近3个月您还没有消费哦~");
        on_pushButton_6_clicked();
    }
    Get_Pages();
    RecordQuery(0);
    Update_Status();
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
    Get_Pages();
    RecordQuery(0);
    Update_Status();
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
        ui->Current_Pages->setHidden(true);
        ui->All_Pages->setHidden(true);
        QMessageBox::warning(this,"暂无消费",QString("在%1，您还没有消费哦~").arg(lefttime.toString("yyyy年MM月")));
        on_pushButton_6_clicked();
    }
    Get_Pages();
    RecordQuery(0);
    Update_Status();
}

void MainWindow::Get_Pages()
{
    Total_RecrodCount=model->rowCount();
    Total_Pages=(Total_RecrodCount%PageRecordCount==0?0:1)+Total_RecrodCount/PageRecordCount;
    Current_Pages=1;
    ui->All_Pages->setText(QString("共%1页").arg(Total_Pages));
    ui->Current_Pages->setText("当前第1页");
}

/*
 * 向前向后按钮是否可以被按下的逻辑判断
 */

void MainWindow::Update_Status()
{
    ui->Current_Pages->setHidden(false);
    ui->All_Pages->setHidden(false);
    if(Current_Pages==1&&Current_Pages==Total_Pages)
    {
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
    }
    else if(Current_Pages==1)
    {
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_7->setEnabled(true);
    }
    else if(Current_Pages==Total_Pages)
    {
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_7->setEnabled(false);
    }
    else {
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
    }
}

void MainWindow::RecordQuery(int limitIndex)
{

    QString szQuery = QString("select * from CardInfo  ORDER BY ID DESC limit %1,%2").arg(QString::number(limitIndex*PageRecordCount+1)).arg(QString::number(PageRecordCount));
    model->QSqlQueryModel::setQuery(szQuery);

}

void MainWindow::on_pushButton_5_clicked()
{
    Current_Pages-=1;
    ui->Current_Pages->setText(QString("当前第%1页").arg(Current_Pages));
    RecordQuery(Current_Pages-1);
    Update_Status();
}

void MainWindow::on_pushButton_7_clicked()
{
    Current_Pages+=1;
    ui->Current_Pages->setText(QString("当前第%1页").arg(Current_Pages));
    RecordQuery(Current_Pages-1);
    Update_Status();
}

void MainWindow::on_pushButton_8_clicked()
{
    long pages=ui->lineEdit->text().toLong();
    if(pages<=0||pages>Total_Pages)
    {
        QMessageBox::warning(this,"输入的页面有误","请输入正确的页数");
        ui->lineEdit->clear();
        return;
    }
    Current_Pages=pages;
    ui->Current_Pages->setText(QString("当前第%1页").arg(Current_Pages));
    RecordQuery(Current_Pages-1);
    Update_Status();
}

void MainWindow::on_pushButton_9_clicked()
{
    printData();

}


void MainWindow::printhtmltoPrinter( const QString & html)
{
    QPrinter  printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QTextDocument textDocument;
        textDocument.setHtml(html);
        textDocument.print(&printer);
    }
}

void MainWindow::printhtmltoPdf(const QString & html)
{
    QString filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        filename += "\\default.pdf";
        filename = QFileDialog::getSaveFileName(this, "Save File", filename, "Adobe PDF Files (*.pdf)");
        if (filename.trimmed() == "") {
            return;
        }

        QPrinter  printer;
        printer.setPageSize(QPrinter::A4);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        QTextDocument textDocument;
        textDocument.setHtml(html);
        textDocument.print(&printer);
}

void MainWindow::printData()
{
    QString html;

    html+="<body><div style='text-align: center'>\
          <h1>账单明细</h1><table border='1' align='center'\
          width='600px' height='50px'><tr><th>流水号</th>\
          <th>类型</th><th>变化金额</th><th>余额</th><th>结算日期</th></tr>";
    for(int i=1;i<model->rowCount();i++)
    {
        QString test="<tr>";
        for(int j=0;j<5;j++)
        {
            test+="<td>";
            QModelIndex index=model->index(i,j,QModelIndex());
            test+=model->data(index).toString();

            test+="</td>";

        }
        test+="</tr>";
        html+=test;
    }
    html+="</tr></table></div></body>";
    qDebug()<<html;
    printhtmltoPrinter(html);
    printhtmltoPdf( html);
}
