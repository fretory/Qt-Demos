#ifndef FUNCDIALOG_H
#define FUNCDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class FuncDialog;
}

class FuncDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FuncDialog(QWidget *parent = nullptr);
    ~FuncDialog();

private slots:
    void on_cardbutton_clicked();

    void on_creditbutoon_clicked();

    void on_storage_button1_clicked();

    void on_storage_button2_clicked();

    void on_credit_button_clicked();

    void on_credit_button_3_clicked();


    void on_comboBox_currentIndexChanged(int index);

    void on_submitn_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::FuncDialog *ui;
    QSqlTableModel *model;//银行卡流水
    void inittable();
    QSqlTableModel *typical;//详细信息
    QSqlTableModel *credit;//信用卡流水
    bool checknumbers(const QString s);
    void Caculate();//储蓄卡利息结算
    void creditCaculate();//信用卡利息计算
};

#endif // FUNCDIALOG_H
