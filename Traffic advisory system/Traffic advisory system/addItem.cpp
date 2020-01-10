#include "addItem.h"


addItem::addItem(QWidget *parent)
{
	ui.setupUi(this);
	selector = new posiselector();


	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	
	QPixmap pixmap = QPixmap(":/Trafficadvisorysystem/pics/longbg.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);

	connect(ui.cancel, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui.submmit, SIGNAL(clicked()), this, SLOT(addEdge()));
	connect(ui.addstart, SIGNAL(clicked()), this, SLOT(selectPosition_s()));
	connect(ui.addterminal, SIGNAL(clicked()), this, SLOT(selectPosition_t()));
	connect(ui.add_station, SIGNAL(clicked()), this, SLOT(addNode()));
	//style
	ui.submmit->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");
	ui.cancel->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");
	ui.add_station->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");
	ui.addstart->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/add_choose.png);}");
	ui.addterminal->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/add_choose.png);}");

	ui.start->setAlignment(Qt::AlignCenter);
	ui.terminal->setAlignment(Qt::AlignCenter);

	QRegExp double_rx("([1-9][0-9]{0,5}[.][0-9]{1,2}|[1-9][0-9]{0,5})");
	ui.price->setValidator(new QRegExpValidator(double_rx, this));
	ui.distance->setValidator(new QRegExpValidator(double_rx, this));

	QRegExp regx_1("^[GTKDL][0-9]{1,5}$");
	ui.uuid->setValidator(new QRegExpValidator(regx_1, this));

	QRegExp regx("^[A-Za-z]+$");
	ui.station_name->setValidator(new QRegExpValidator(regx, this));
}


addItem::~addItem()
{
}

void addItem::cancel(){
	this->close();
}
void addItem::addEdge(){
	//QString start = ui.start->text();
	//QTime deptime = ui.timeEdit_2->time();
	//QTime timecost =
	if (ui.start->text().isEmpty() || ui.terminal->text().isEmpty() || ui.distance->text().isEmpty()){
		QMessageBox::warning(this, "warning", "Please complete the information");
		return;
	}
	if (QString(ui.uuid->text()).isEmpty() || QString(ui.price->text()).isEmpty()){
		QMessageBox::warning(this, "warning", "Please complete the information");
		return;
	}
	int start = find_node(ui.start->text());
	int dest = find_node(ui.terminal->text());
	if (start == -1 || dest == -1){
		QMessageBox::warning(this, "warning", "Enter the right station");
		return;
	}
	QTime deptime = ui.timeEdit_2->time();
	QTime timecost = ui.timeEdit->time();
	double discost = ui.distance->text().toDouble();
	double price = ui.price->text().toDouble();
	QString uuid = ui.uuid->text();
	int type = ui.comboBox->currentIndex();
	EdgeNode edge(dest, deptime, timecost, discost, uuid, type,price);
	emit retEdge(start,edge);
}

void addItem::updateEdge(vector<QString> V){
	VA.clear();
	VA.assign(V.begin(), V.end());
}

int addItem::find_node(const QString &v){
	for (int i = 0; i < VA.size(); i++)
	{
		if (!VA[i].compare(v))
		{
			return i;
		}
	}
	return -1;
}

void addItem::selectPosition_s(){
	selector->updateItem(VA);
	selector->show();
	connect(selector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_s(QString)));
}
void addItem::selectPosition_t(){
	selector->updateItem(VA);
	selector->show();
	connect(selector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_t(QString)));
}

void addItem::changetPosition_s(QString loc){
	ui.start->setText(loc);
	disconnect(selector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_s(QString)));
}

void addItem::changetPosition_t(QString loc){
	ui.terminal->setText(loc);
	disconnect(selector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_t(QString)));
}

void addItem::addNode(){
	QString station = ui.station_name->text();
	if (station.isEmpty()){
		QMessageBox::warning(this, "warning", "Enter the right station name !");
		return;
	}
	emit retNode(station.toUpper());
}