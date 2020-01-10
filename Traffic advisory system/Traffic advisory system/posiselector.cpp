#include "posiselector.h"
#include<qdebug.h>

posiselector::posiselector(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);  //±³¾°Í¸Ã÷»¯
	ui.qtablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.qtablewidget->verticalHeader()->setVisible(false);
	ui.qtablewidget->horizontalHeader()->setVisible(false);
	//ui.qtablewidget->resizeColumnsToContents();
	ui.qtablewidget->resizeRowsToContents();
	ui.qtablewidget->horizontalHeader()->resizeSection(0, 29);
	ui.qtablewidget->horizontalHeader()->resizeSection(1, 29);
	ui.qtablewidget->horizontalHeader()->resizeSection(2, 29);

	connect(ui.qtablewidget, SIGNAL(cellClicked(int, int)), this, SLOT(getloc(int,int)));
	
}


posiselector::~posiselector()
{
}

void posiselector::updateItem(vector<QString> VA){
	if (VA.empty())
	{
		return;
	}
	ui.qtablewidget->clearContents();
	ui.qtablewidget->setRowCount(VA.size() / 3 + 1);

	int x = 0;
	int y = 0;
	for (int i = 0; i < VA.size(); i++){
		if (i > 0 && i % 3 == 0){
			x = 0;
			y = y + 1;
		}
		ui.qtablewidget->setItem(y, x, new QTableWidgetItem(VA[i]));
		qDebug() << VA[i];
		x++;
	}
	
}

void posiselector::getloc(int i, int j){
	QString s = ui.qtablewidget->item(i, j)->text();
	emit Slocation(s);
	this->close();
}