#ifndef posiselector_h
#define posiselector_h

#include <QtWidgets/QWidget>
#include "ui_posiselector.h"
#include<vector>

using namespace std;

class posiselector :
	public QWidget
{
	Q_OBJECT
public:
	posiselector(QWidget *parent = 0);
	~posiselector();
	void updateItem(vector<QString> VA);
private:
	Ui::PosiSelector ui;
public slots:
	void getloc(int i, int j);
signals:
	void Slocation(QString loc);
};

#endif