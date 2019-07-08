#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlTableModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void init();
    QSqlTableModel *model;
    void setui();
};

#endif // MAINWINDOW_H
