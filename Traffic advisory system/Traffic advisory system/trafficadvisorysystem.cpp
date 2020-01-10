#include "trafficadvisorysystem.h"
#include <qdebug.h>
#include<fstream>
Trafficadvisorysystem::Trafficadvisorysystem(QWidget *parent)
	: QWidget(parent)
{
	PositionSelector = new posiselector(this);
	additem = new addItem(this);
	initUI();
	readData();
	initModel();
	PositionSelector->updateItem(data->VA);
	updateAlldata();
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(onCloseButton()));
	connect(ui.minButton, SIGNAL(clicked()), this, SLOT(onMinszButton()));
	connect(ui.select_01, SIGNAL(clicked()), this, SLOT(selectPosition_l()));
	connect(ui.select_02, SIGNAL(clicked()), this, SLOT(selectPosition_r()));
	connect(ui.eButton, SIGNAL(clicked()), this, SLOT(eButtonaction()));
	connect(ui.qButton, SIGNAL(clicked()), this, SLOT(qButtonaction()));
	connect(ui.updateButton, SIGNAL(clicked()), this, SLOT(update()));
	connect(ui.delButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addItemOn()));
	connect(additem, SIGNAL(retNode(QString)), this, SLOT(addNode(QString)));
	connect(additem, SIGNAL(retEdge(int, EdgeNode)), this, SLOT(addEdge(int, EdgeNode)));
	connect(ui.changeButton, SIGNAL(clicked()), this, SLOT(editvalue()));
	connect(ui.tableView_2, SIGNAL(clicked(const QModelIndex &)), this, SLOT(foucusChange(const QModelIndex &)));
	connect(ui.queryButton, SIGNAL(clicked()), this, SLOT(queryButton()));
}
void Trafficadvisorysystem::initUI(){
	ui.setupUi(this);
	
	//set the pixmap
	ui.trans->setPixmap(QPixmap(":/Trafficadvisorysystem/pics/right.png").scaled(ui.trans->size(), Qt::KeepAspectRatio));
	ui.trans->setScaledContents(true);

	ui.timeEdit->setVisible(false);
	ui.typechoose->setVisible(false);

	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/Trafficadvisorysystem/pics/background1000600.png").scaled(// 缩放背景图.
		this->size(),
		Qt::IgnoreAspectRatio,
		Qt::SmoothTransformation)));             // 使用平滑的缩放方式
	this->setPalette(palette);                           // 给widget加上背景图
	this->setWindowFlags(Qt::FramelessWindowHint);


	ui.minButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/min.png);}");
	ui.closeButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/close.png);}");

	ui.eButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");
	ui.qButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");
	ui.queryButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/button.png);}");

	ui.select_01->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.select_02->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	
	ui.addButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.delButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.changeButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.saveButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.updateButton->setStyleSheet("QPushButton{border-image:url(:/Trafficadvisorysystem/pics/smallButton.png);}");
	ui.tableView->setStyleSheet("QTableView {color: black;gridline - color: black;background - color: rgb(108, 108, 108);alternate-background-color:rgb(64, 64, 64);selection-color:white;selection-background-color:rgb(77, 77, 77);border:2px groove gray;border - radius: 0px;padding: 2px 4px;}");
	ui.tableView_2->setStyleSheet("QTableView {color: black;gridline - color: black;background - color: rgb(108, 108, 108);alternate-background-color: rgb(64, 64, 64);selection-color:white;selection-background-color:rgb(77, 77, 77);border:2px groove gray;border - radius: 0px;padding: 2px 4px;}");
	QStringList qss;
	qss.append(QString("QLineEdit{border-style:none;padding:6px;border-radius:2px;border:2px solid white;}"));
	qss.append(QString("QLineEdit:focus{border:2px solid black;}"));
	ui.lineEdit->setStyleSheet(qss.join(""));

	ui.start->setAlignment(Qt::AlignCenter);
	ui.end->setAlignment(Qt::AlignCenter);

	pButtonGroup = new QButtonGroup(this);
	pButtonGroup->addButton(ui.PriceradioButton,0);
	pButtonGroup->addButton(ui.TimeradioButton,1);

	ui.PriceradioButton->setChecked(true);
}

void Trafficadvisorysystem::readData(){
	//read the information
	data = new Graph();
	ifstream in;
	in.open("./data.txt", ifstream::in);
	if (!in){
		qDebug() << "can't read file" << endl;
	}
	in >> *data;
	
}
Trafficadvisorysystem::~Trafficadvisorysystem()
{

}
void Trafficadvisorysystem::onCloseButton(){
	this->close();
}

void Trafficadvisorysystem::onMinszButton(){
	this->showMinimized();
}

void Trafficadvisorysystem::selectPosition_l(){
	PositionSelector->updateItem(data->VA);
	PositionSelector->show();
	connect(PositionSelector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_l(QString)));
}
void Trafficadvisorysystem::selectPosition_r(){
	PositionSelector->updateItem(data->VA);
	PositionSelector->show();
	connect(PositionSelector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_r(QString)));
}

void Trafficadvisorysystem::changetPosition_l(QString loc){
	ui.start->setText(loc);
	disconnect(PositionSelector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_l(QString)));
}
void Trafficadvisorysystem::changetPosition_r(QString loc){
	ui.end->setText(loc);
	disconnect(PositionSelector, SIGNAL(Slocation(QString)), this, SLOT(changetPosition_r(QString)));
}

void Trafficadvisorysystem::eButtonaction(){
	ui.eButton->setDisabled(true);
	ui.qButton->setEnabled(true);
	ui.stackedWidget->setCurrentIndex(1);
	updateAlldata();
}
void Trafficadvisorysystem::qButtonaction(){
	ui.qButton->setDisabled(true);
	ui.eButton->setEnabled(true);
	ui.stackedWidget->setCurrentIndex(0);
}

void Trafficadvisorysystem::initModel(){
	modelAll = new QStandardItemModel();
	modelAll->setColumnCount(8);
	modelAll->setHeaderData(0, Qt::Horizontal, QString("Origin"));
	modelAll->setHeaderData(1, Qt::Horizontal, QString("Terminal"));
	modelAll->setHeaderData(2, Qt::Horizontal, QString("Departure Time"));
	modelAll->setHeaderData(3, Qt::Horizontal, QString("Time costs"));
	modelAll->setHeaderData(4, Qt::Horizontal, QString("Distance"));
	modelAll->setHeaderData(5, Qt::Horizontal, QString("trans-ID"));
	modelAll->setHeaderData(6, Qt::Horizontal, QString(" type"));
	modelAll->setHeaderData(7, Qt::Horizontal, QString("price"));
	ui.tableView_2->setModel(modelAll);
	ui.tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	modelQuery = new QStandardItemModel();
	modelQuery->setColumnCount(8);
	modelQuery->setHeaderData(0, Qt::Horizontal, QString("Origin"));
	modelQuery->setHeaderData(1, Qt::Horizontal, QString("Terminal"));
	modelQuery->setHeaderData(2, Qt::Horizontal, QString("Departure Time"));
	modelQuery->setHeaderData(3, Qt::Horizontal, QString("Time costs"));
	modelQuery->setHeaderData(4, Qt::Horizontal, QString("Distance"));
	modelQuery->setHeaderData(5, Qt::Horizontal, QString("trans-ID"));
	modelQuery->setHeaderData(6, Qt::Horizontal, QString(" type"));
	modelQuery->setHeaderData(7, Qt::Horizontal, QString("price"));
	ui.tableView->setModel(modelQuery);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	ui.tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void Trafficadvisorysystem::updateAlldata(){
	modelAll->removeRows(0, modelAll->rowCount());
	
	int x = 0;
	for (int i = 0; i < data->VA.size(); i++){
		QList<EdgeNode>::iterator first = data->HL[i]->begin();
		QList<EdgeNode>::iterator last = data->HL[i]->end();
		for (; first != last; ++first){
			modelAll->setItem(x, 0, new QStandardItem(data->VA[i]));
			modelAll->setItem(x, 1, new QStandardItem(data->VA[(first->dest)]));
			modelAll->setItem(x, 2, new QStandardItem(first->deptime.toString("hh:mm")));
			modelAll->setItem(x, 3, new QStandardItem(first->timecost.toString("hh:mm")));
			modelAll->setItem(x, 4, new QStandardItem(QString("%1").arg(first->discost)));
			modelAll->setItem(x, 5, new QStandardItem(first->uuid));
			if (first->type == 0){ modelAll->setItem(x, 6, new QStandardItem("train")); }
			else{ modelAll->setItem(x, 6, new QStandardItem("plane")); }
			modelAll->setItem(x, 7, new QStandardItem(QString("%1").arg(first->price)));
			x++;
		}
	}
}

void Trafficadvisorysystem::deleteItem(){
	int row = ui.tableView_2->currentIndex().row();

	QString s = modelAll->item(row, 0)->text();
	QString e = modelAll->item(row, 1)->text();
	QString u = modelAll->item(row, 5)->text();

	if (data->deleteE(s, e, u)){
		modelAll->removeRow(row);
		QMessageBox::information(this, "Info", "Delete Successfully");
		}
	else{
		QMessageBox::warning(this, "Warning", "Delete Failed");
	}

}

void Trafficadvisorysystem::addItemOn(){
	additem->updateEdge(data->VA);
	additem->show();
}
void Trafficadvisorysystem::addEdge(int s, EdgeNode e){
	additem->close();
	if (data->insertE(s, e)){
		QMessageBox::information(this, "Successful", "Add Successfully");
	}
	else{
		QMessageBox::warning(this, "Error", "The uuid can't be the same !");
	}
	
	updateAlldata();
}

void Trafficadvisorysystem::addNode(QString s){
	additem->close();
	int pos = data->find_node(s);
	if (pos!=-1){
		QMessageBox::warning(this, "Error", "The station already exists !");
		return;
	}
	data->insertV(s);
	QMessageBox::information(this, "Successful", "Add Station  Successfully");
}

void Trafficadvisorysystem::editvalue(){
	//modelAll->setHeaderData(0, Qt::Horizontal, QString("Origin"));
	//modelAll->setHeaderData(1, Qt::Horizontal, QString("Terminal"));
	//modelAll->setHeaderData(2, Qt::Horizontal, QString("Departure Time"));
	//modelAll->setHeaderData(3, Qt::Horizontal, QString("Time costs"));
	//modelAll->setHeaderData(4, Qt::Horizontal, QString("Distance"));
	//modelAll->setHeaderData(5, Qt::Horizontal, QString("trans-ID"));
	//modelAll->setHeaderData(6, Qt::Horizontal, QString(" type"));
	//modelAll->setHeaderData(7, Qt::Horizontal, QString("price"));


	int row = ui.tableView_2->currentIndex().row();
	int col = ui.tableView_2->currentIndex().column();
	QString s = ui.lineEdit->text();

	QString start = modelAll->item(row, 0)->text();
	QString dest = modelAll->item(row, 1)->text();
	QString uuid = modelAll->item(row, 5)->text();
	//查找到这个要被修改的节点在data中的迭代器
	auto edge = data->findrecord(start, dest, uuid);
	if (edge == QList<EdgeNode>::iterator(nullptr)){
		QMessageBox::warning(this, "Warning", "Get the node Failed");
		return;
	}
	 
	if (col == 0 || col == 1 || col == 4 || col == 5 || col == 7){
		if (s.isEmpty()){
			QMessageBox::warning(this, "Warning", "Please input a value !");
			return;
		}
	}

	EdgeNode temp = *edge;

	switch (col)
	{
	case 0:{
		int startindex = data->find_node(s.toUpper());
		int destindex = data->find_node(dest);
			if (startindex == -1 || startindex==destindex){
			QMessageBox::warning(this, "Warning", "Station not exists \n or start and end can't be the same !");
			return;
		}
		data->deleteE(start, dest, uuid);
		data->insertE(startindex, temp);
		break; }

	case 1:{
		int startindex = data->find_node(start);
		int desttindex = data->find_node(s.toUpper());
		if (desttindex == -1 || startindex==desttindex){
			QMessageBox::warning(this, "Warning", "Station not exists \n or start and end can't be the same !");
			return;
		}
		edge->dest = desttindex;
		break;
	}
	case 2:{
		QTime temp = ui.timeEdit->time();
		edge->deptime = temp;
		break; }
	case 3:{
		QTime temp = ui.timeEdit->time();
		edge->timecost = temp;
		break; }
	case 4:{
		double temp = s.toDouble();
		edge->discost = temp;
		break; }
	case 5:{
		if (!data->uuidexists(s)){
			edge->uuid = s;
		}
		else{
			QMessageBox::warning(this, "Warning", "Trans-id already exists !");
			return;
		}
		break; }
	case 6:{
		int type = ui.typechoose->currentIndex();
		edge->type = type;
		break; }
	case 7:{
		double temp = s.toDouble();
		edge->price = temp;
		break; }
	default:
		break;
	}
	updateAlldata();
}

void Trafficadvisorysystem::foucusChange(const QModelIndex &index){
	int col = index.column();
	if (col == 2 || col == 3){
		ui.timeEdit->setVisible(true);
		ui.lineEdit->setVisible(false);
		ui.typechoose->setVisible(false);
	}
	else if (col == 6){
		ui.timeEdit->setVisible(false);
		ui.lineEdit->setVisible(false);
		ui.typechoose->setVisible(true);
	}
	else{
		ui.lineEdit->clear();
		ui.timeEdit->setVisible(false);
		ui.lineEdit->setVisible(true);
		ui.typechoose->setVisible(false);
		if (col == 7 || col == 4){
			QRegExp double_rx("([1-9][0-9]{0,5}[.][0-9]{1,2}|[1-9][0-9]{0,5})");
			ui.lineEdit->setValidator(new QRegExpValidator(double_rx, this));
		}
		else if (col == 5){
			QRegExp regx("^[GTKDL][0-9]{1,5}$");
			ui.lineEdit->setValidator(new QRegExpValidator(regx, this));
		}
		else{
			QRegExp regx("^[A-Za-z]+$");
			ui.lineEdit->setValidator(new QRegExpValidator(regx, this));
		}
	}
}

void Trafficadvisorysystem::queryButton(){

	int s = data->find_node(ui.start->text());
	int j = data->find_node(ui.end->text());
	if (s == -1 || j == -1){ return; }
	if (s == j){
		QMessageBox::warning(this, "Warning", "Station not exists \n or start and end can't be the same !");
	}
	int traffic = ui.queryMode->currentIndex();
	qDebug() << traffic;
	int priority = pButtonGroup->checkedId();
	qDebug() << priority;
	data->changeMode(traffic, priority);
	vector<PathData> res = data->get_solution(ui.start->text(), ui.end->text());

	if (res.empty()){
		QMessageBox::warning(this, "Warning", "can't reach!");
	}
	modelQuery->clear();
	modelQuery->setColumnCount(8);
	modelQuery->setHeaderData(0, Qt::Horizontal, QString("Origin"));
	modelQuery->setHeaderData(1, Qt::Horizontal, QString("Terminal"));
	modelQuery->setHeaderData(2, Qt::Horizontal, QString("Departure Time"));
	modelQuery->setHeaderData(3, Qt::Horizontal, QString("Time costs"));
	modelQuery->setHeaderData(4, Qt::Horizontal, QString("Distance"));
	modelQuery->setHeaderData(5, Qt::Horizontal, QString("trans-ID"));
	modelQuery->setHeaderData(6, Qt::Horizontal, QString(" type"));
	modelQuery->setHeaderData(7, Qt::Horizontal, QString("price"));

	int x = 0;
	while (!res.empty())
	{
		PathData tempPath = res.back();
		res.pop_back();
		auto first = data->findrecord(data->VA[tempPath.start], data->VA[tempPath.dest], tempPath.uuid);
		modelQuery->setItem(x, 0, new QStandardItem(data->VA[tempPath.start]));
		modelQuery->setItem(x, 1, new QStandardItem(data->VA[tempPath.dest]));
		modelQuery->setItem(x, 2, new QStandardItem(first->deptime.toString("hh:mm")));
		modelQuery->setItem(x, 3, new QStandardItem(first->timecost.toString("hh:mm")));
		modelQuery->setItem(x, 4, new QStandardItem(QString("%1").arg(first->discost)));
		modelQuery->setItem(x, 5, new QStandardItem(first->uuid));
		if (first->type == 0){ modelQuery->setItem(x, 6, new QStandardItem("train")); }
		else{ modelQuery->setItem(x, 6, new QStandardItem("plane")); }
		modelQuery->setItem(x, 7, new QStandardItem(QString("%1").arg(first->price)));
		x++;
	}

}