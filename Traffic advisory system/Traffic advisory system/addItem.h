
#ifndef addItem_h
#define addItem_h

#include "Graph.h"
#include <QtWidgets/QWidget>
#include "ui_add.h"
#include<vector>
#include<qdatetime.h>
#include<qmessagebox.h>
#include"posiselector.h"

using namespace std;

class addItem :
	public QWidget
{
	Q_OBJECT
public:
	addItem(QWidget *parent = 0);
	~addItem();
	void updateEdge(vector<QString> V);
private:
	Ui::ADDITEM ui;
	vector<QString> VA;
	posiselector *selector;
	int find_node(const QString &v);
public slots:
	void cancel();
	void addEdge();
	void selectPosition_s();
	void selectPosition_t();
	void changetPosition_s(QString loc);
	void changetPosition_t(QString loc);
	void addNode();
signals:
	void retEdge(int s,EdgeNode e);
	void retNode(QString s);
};

#endif