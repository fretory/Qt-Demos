#ifndef Graph_h
#define Graph_h


#include <iostream>
#include <vector>
#include <qlist>
#include <queue>
#include<qdatetime.h>
#include <QDebug>
using namespace std;

//a very very large number
//in my opinion ,the a ticket or a distance is lager than this
//it's only shit !
#define MAXWEIGHT 9999999999.0

struct EdgeNode
{
	int dest;		//destination
	QTime deptime;		//Departure time
	QTime timecost;		//time cost
	double discost;		//distance cost
	QString uuid;		//train or plain number
	int type;			//0 train ,1 plain
	double price;		//tickets price


	EdgeNode(int d, int d1, int d2, int t1, int t2, double dis, QString u, int t, double p)
		: dest(d), deptime(d1, d2), timecost(t1, t2), discost(dis), uuid(u), type(t), price(p) {}


	EdgeNode(int d, QTime dep, QTime time, double dis, QString u, int t, double p)
		: dest(d), deptime(dep), timecost(time), discost(dis), uuid(u), type(t), price(p) {}
};

struct PathData{
	int start, dest;
	double cost;
	QString uuid;
	operator double(){ return cost; }
};

class Graph
{
private:
	int TrafficMode = 0;			// 0:train 1:plane
	int Priority = 0;			   //  1:time first 0:money money go my home
	QTime arrvialTime;
	bool isStart;
	void BuildHeap(vector<PathData>& E, int size);
	void PercolateDown(vector<PathData>& E, int pos, int size);
	void PercolateUp(vector<PathData>& E, int pos);
public:	
	vector<QString> VA;                //Point
	vector<QList<EdgeNode> *> HL;     //list for edge
	int sizeE;                       //numbers of Point

	Graph();
	~Graph();
	int empty() { return VA.empty(); }
	int get_sizeV() { return VA.size(); }	//get numbers of Point
	int get_sizeE() { return sizeE; }		//get numbers of sides of a Point
	int find_node(const QString &v);		//get the index of a node

	//basic operation
	bool insertV(const QString &v);																								//insert a station
	bool insertE(const QString &v1, const QString &v2, int d1, int d2, int t1, int t2, double dis, QString u, int t, double p);	//insert a flight
	bool insertE(int pos, EdgeNode e);
	bool deleteV(const QString &v);																								//delete a statio
	bool deleteE(const QString &v1, const QString &v2, const QString &uuid);													//delete a flight
	int getEdgeNum(int index);
	QList<EdgeNode>::iterator findrecord(const QString &v1, const QString &v2, const QString &uuid);
	friend istream &operator>>(istream &istr, Graph &g);
	friend ostream &operator<<(ostream &ostr, Graph &g);
	bool uuidexists(const QString & u);
	void changeMode(int t, int p){ TrafficMode = t; Priority = p; }
	vector<PathData> dijkstra(const QString &v, vector<double>& D, vector<int>& P);
	double get_cost(int s, int j,QString &transID);
	vector<PathData> get_solution(QString s, QString l);
};




#endif
