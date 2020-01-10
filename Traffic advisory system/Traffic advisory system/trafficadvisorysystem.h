#ifndef TRAFFICADVISORYSYSTEM_H
#define TRAFFICADVISORYSYSTEM_H

#include "Graph.h"
#include "posiselector.h"
#include <QtWidgets/QWidget>
#include "ui_trafficadvisorysystem.h"
#include <QStandardItemModel> 
#include <QDialog>
#include<qmessagebox.h>
#include"addItem.h"
class Trafficadvisorysystem : public QWidget
{
	Q_OBJECT

public:
	Trafficadvisorysystem(QWidget *parent = 0);
	~Trafficadvisorysystem();

private:
	Ui::TrafficadvisorysystemClass ui;
	Graph *data;
	addItem * additem;//增加记录
	posiselector *PositionSelector;//选择节点
	QStandardItemModel *modelQuery;
	QStandardItemModel *modelAll;
	QButtonGroup* pButtonGroup;//用来让radioBox为单选的。
	void initUI();
	void readData();
	void updateAlldata();
	void initModel();
public slots:
	void onCloseButton();
	void onMinszButton();
	void selectPosition_l();
	void selectPosition_r();
	void changetPosition_l(QString loc);
	void changetPosition_r(QString loc);
	void eButtonaction();
	void qButtonaction();
	void update(){ updateAlldata(); QMessageBox::information(this, "info", "Update Successfully"); }
	void deleteItem();
	void addItemOn();
	void addEdge(int s, EdgeNode e);
	void addNode(QString s);
	void editvalue();
	void foucusChange(const QModelIndex &index);
	void queryButton();
};

#endif // TRAFFICADVISORYSYSTEM_H
