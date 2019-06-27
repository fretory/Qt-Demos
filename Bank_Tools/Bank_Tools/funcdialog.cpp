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
#include <QTableView>
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
    //inittable();
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);




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
    //界面跳转到卡号信息这里
    ui->TOTAL->setCurrentIndex(0);
    ui->storage_func->setCurrentIndex(0);
    inittable();
    Caculate();
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
    inittable();

}

void FuncDialog::inittable()
{

    QSqlDatabase db;
    if(QSqlDatabase::contains())
        db = QSqlDatabase::database();
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

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
    db.close();
    //QSqlDatabase::removeDatabase();
}
void FuncDialog::on_credit_button_clicked()
{
    ui->TOTAL->setCurrentIndex(1);
    ui->credit_func->setCurrentIndex(0);


    QSqlDatabase db;
    if(QSqlDatabase::contains("creditInfo"))
        db = QSqlDatabase::database("creditInfo");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","creditInfo");
    db.setDatabaseName("../info.db");
    if(!db.open())//如果打开数据库失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    QString s="SELECT * FROM CreditCard";
    QSqlQuery query(db);

    query.exec(s);
    if(query.next())
    {
        ui->info1->setText(query.value(0).toString());
        ui->info1_2->setText(query.value(1).toString());
        ui->info1_3->setText(query.value(2).toString());
        ui->info1_4->setText(query.value(3).toString());
        ui->info1_5->setText(query.value(4).toString());
    }
    db.close();

}

//流水信息

void FuncDialog::on_credit_button_3_clicked()
{
    ui->TOTAL->setCurrentIndex(1);
    ui->credit_func->setCurrentIndex(1);

    QSqlDatabase db;
    if(QSqlDatabase::contains("water"))
        db = QSqlDatabase::database("water");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","water");

    db.setDatabaseName("../info.db");



    if(!db.open())//如果打开数据库失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    //设置模型
    credit = new QSqlTableModel(this);
    //指定使用哪个表
    credit->setTable("CreditList");

    //把model放到view
    //view中的数据库不允许修改
    ui->Credit_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Credit_table->setModel(credit);
    ui->Credit_table->verticalHeader()->hide();
    credit->select();
    credit->setHeaderData(0,Qt::Horizontal,"流水号");
    credit->setHeaderData(1,Qt::Horizontal,"变化金额");
    credit->setHeaderData(2,Qt::Horizontal,"类型");
    credit->setHeaderData(3,Qt::Horizontal,"结算日期");
    credit->setHeaderData(4,Qt::Horizontal,"剩余额度");
    credit->setHeaderData(5,Qt::Horizontal,"余额");

    db.close();
}


//账户概览
void FuncDialog::on_comboBox_currentIndexChanged(int index)
{

    QSqlDatabase db;
    if(QSqlDatabase::contains("change"))
        db = QSqlDatabase::database("change");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","change");

    db.setDatabaseName("../info.db");
    QString cardid;
    switch (index) {
    case 1:cardid="c_445989";break;
    case 2:cardid="c_467149";break;
    case 3:cardid="c_498138";break;
    case 4:cardid="c_440410";break;
    case 5:cardid="c_455086";break;
    default:return;
    }



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

    if(!checknumbers(QString(ui->changesline->text())))
    {
        QMessageBox::warning(this,"Error","请输入正确的金额");
        return;
    }


    QString ID;
    QString cardid;
    switch (ui->comboBox->currentIndex()) {
        case 1:cardid="c_445989";ID="445989";break;
        case 2:cardid="c_467149";ID="467149";break;
        case 3:cardid="c_498138";ID="498138";break;
        case 4:cardid="c_440410";ID="440410";break;
        case 5:cardid="c_455086";ID="455086";break;
        default:return;
    }

    QSqlDatabase db;
    if(QSqlDatabase::contains("edit"))
        db = QSqlDatabase::database("edit");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","edit");


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

    //如果结算后所得到的金额小于0
    //清空输入框
    //设置锁定
    if(last<0)
    {
        QMessageBox::warning(this,"Error","非法的金额");
        ui->changesline->clear();
        ui->changesline->setFocus();
        return;
    }


    QSqlQuery query;    //用于执行sql语句的对象
    QString s=QString("INSERT INTO %1 VALUES (%2, '%3', %4,%5, '%6' )").arg(cardid).arg(id).arg(Outtype).
            arg(ui->changesline->text()).arg(double(last)).arg(strtime);
    query.exec(s);
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());

    QSqlQuery editCardInfo;
    QString c=QString("UPDATE CardInfo SET BALANCE = %1 WHERE ID = %2;").arg(double(last)).arg(ID);
    editCardInfo.exec(c);
    on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}

//检测用户输入的是不是纯数字
 bool FuncDialog::checknumbers(const QString s)
 {
    for(int i=0;i<s.size();i++)
        if(s[i]>'9'||s[i]<'0')
            return false;
    return true;
 }

void FuncDialog::on_pushButton_1_clicked()
{
    /*
     * 前一部分判断模式，已经输入是不是正确金额
     */
    QString type;
    int flag;//判断模式
    if(ui->radioButton->isChecked())
    {
        type="透支";
        flag=1;
    }
    else if (ui->radioButton_2->isChecked()) {
        flag=2;
    }
    else {
        QMessageBox::warning(this,"Error","请选择还款或者透支");
        return;
    }

    if(!checknumbers(QString(ui->Money_line->text())))
    {
        QMessageBox::warning(this,"Error","请输入正确的金额");
        ui->Money_line->clear();
        ui->Money_line->setFocus();
        return;
    }

    /*
     * 连接数据库
     */

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
    QSqlQuery editCardInfo(db);
    /* 此处是获取一些接下来可能会用到的数据*/


    QSqlQuery temp(db);
    temp.exec(QString("select * from CreditList"));

    int id=0;
    double left=0;
    double deposit=0;//记录最后一次的额度
    while(temp.next())
    {
        id=temp.value(0).toInt();
        left=temp.value(4).toDouble();
        deposit=temp.value(5).toDouble();
    }
    id+=1;


    QString Outtype;
    //获取日期
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strtime = time.toString("yyyy-MM-dd");

    /*分支操作透支或者存款*/
    double Money_Input=ui->Money_line->text().toDouble();
    if(flag==1)
    {
        if(Money_Input>left)
        {
            QMessageBox::warning(this,"失败","透支失败:超过您的信用额度!");
            ui->Money_line->clear();
            ui->Money_line->setFocus();
            return;
        }
        if(deposit<=0)
        {
            left=left-Money_Input;
        }
        else
        {
            if(deposit-Money_Input>0)
            {
                deposit=deposit-Money_Input;
            }
            else
            {
                left=left-Money_Input+deposit;
                deposit=0;
            }
        }
        QString s=QString("INSERT INTO CreditList VALUES (%1,%2,'%3', '%4',%5,%6);").arg(id).arg(double(Money_Input)).arg(type)
                .arg(strtime).arg(double(left)).arg(double(deposit));

        editCardInfo.exec(s);
        ui->Money_line->clear();
        ui->Money_line->setFocus();
        on_credit_button_3_clicked();
        return;
    }
    else {
        QString s;
        if(deposit>0)
        {
            deposit+=Money_Input;
            s=QString("INSERT INTO CreditList VALUES (%1,%2,'存款', '%3',%4,%5);").arg(id).arg(double(Money_Input))
                    .arg(strtime).arg(double(left)).arg(double(deposit));
        }
        else {
            double quota;
            s=QString("select * from CreditCard");
            temp.exec(s);
            if(temp.next())
                quota=temp.value(1).toDouble();
            else {
                QMessageBox::warning(this,"错误","查询额度失败!");
                return;
            }

            /*检查存款金与消费金的关系*/
            double repay=quota-left;
            if(Money_Input>repay)
            {
                left=quota;
                deposit=Money_Input-repay;
            }
            else {
                left=left+Money_Input;
            }

            s=QString("INSERT INTO CreditList VALUES (%1,%2,'还款', '%3',%4,%5);").arg(id).arg(double(Money_Input))
                    .arg(strtime).arg(double(left)).arg(double(deposit));

        }
        editCardInfo.exec(s);
        ui->Money_line->clear();
        ui->Money_line->setFocus();
        on_credit_button_3_clicked();

    }
}

void FuncDialog::Caculate()
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
    QSqlQuery editCardInfo(db);
    /* 此处是获取一些接下来可能会用到的数据*/


    QSqlQuery temp(db);
    temp.exec(QString("select * from CardInfo"));
    while(temp.next())
    {
        QDate curDateTime=QDate::currentDate();
        QDate last=temp.value(3).toDate();
        QString cardid=temp.value(0).toString();
        if(last.addDays(30)<=curDateTime)
        {
            QMessageBox::about(this, "结息",QString("今天是卡号%1的结息日期").arg(cardid));
            QString tablename="c_"+cardid;
            double rate=temp.value(2).toDouble();//获取
            double left=temp.value(1).toDouble();//获取余额


            QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
            QString strtime = time.toString("yyyy-MM-dd");

            QSqlQuery temp1(db);
            temp1.exec(QString("select * from %1").arg(tablename));
            int id=0;
            while(temp1.next())
            {
                id=temp1.value(0).toInt();
            }

            id+=1;

            QString query=QString("INSERT INTO %1 VALUES (%2, '%3', %4,%5, '%6' )").arg(tablename).arg(id).arg("利息结算").
                    arg(left*rate).arg(left*(rate+1)).arg(strtime);
             QSqlQuery doit(db);
             doit.exec(query);
             QString maintable=QString("update CardInfo set BALANCE =%1,SETTLE='%2' where ID==%3").arg(left*(rate+1)).arg(strtime).arg(cardid);
             doit.exec(maintable);
            on_storage_button1_clicked();
        }
    }

}
