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

private:
    Ui::FuncDialog *ui;
    QSqlTableModel *model;
    void inittable();
    QSqlTableModel *typical;//详细信息
};

#endif // FUNCDIALOG_H
