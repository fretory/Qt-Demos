#include "Graph.h"

//tools:transform std:string to QString
QString transfromstd(string &s){
	return QString::fromStdString(s);
}

Graph::Graph()
{
	sizeE = 0;
}


Graph::~Graph()
{
	HL.clear();
}

int Graph::find_node(const QString &v){
	for (int i = 0; i < VA.size(); i++)
	{
		if (!VA[i].compare(v))
		{
			return i;
		}
	}
	return -1;
}

bool Graph::insertV(const QString &v)
{

	VA.push_back(v);
	HL.push_back(new QList<EdgeNode>());
	return true;

}

bool Graph::insertE(const QString &v1, const QString &v2, int d1, int d2, int t1, int t2, double dis, QString u, int t, double p){
	int si = find_node(v1);
	int dj = find_node(v2);
	if (si == -1 || dj == -1)
	{
		return false;
	}

	EdgeNode en(dj, d1, d2, t1, t2, dis, u, t, p);
	HL[si]->push_back(en);
	sizeE++;
	return true;
}

bool Graph::uuidexists(const QString & u){
	for (int i = 0; i < VA.size(); i++){
		auto first = HL[i]->begin();
		auto last = HL[i]->end();

		for (; first != last; first++){
			if (!first->uuid.compare(u)){
				return true;
			}
		}

	}
	return false;
}

bool Graph::insertE(int pos, EdgeNode e){
	if (pos >= VA.size()){ return false; }
	auto first = HL[pos]->begin();
	auto last = HL[pos]->begin();
	
	//judge if the uuid exists
	if (!uuidexists(e.uuid)){ 
		HL[pos]->push_back(e); 
		return true;
	}
	else{
		return false;
	}
	
	
}

istream  &operator>>(istream &istr, Graph &g){
	char s[50];
	int n;
	double w;
	string v1, v2;
	istr >> s >> n;
	for (int i = 0; i < n; i++)
	{
		istr >> v1;
		g.insertV(transfromstd(v1));

	}

	int d1, d2, t1, t2, t;
	double dis, p;
	string u;

	istr >> s >> n;
	for (int i = 0; i < n; i++)
	{
		istr >> v1 >> v2 >> d1 >> d2 >> t1 >> t2 >> dis >> u >> t >> p;
		g.insertE(transfromstd(v1), transfromstd(v2), d1, d2, t1, t2, dis, transfromstd(u), t, p);
	}

	return istr;
}

ostream &operator<<(ostream &ostr, Graph &g)
{
	for (int i = 0; i < g.VA.size(); i++)
	{
		ostr << i << "-" << g.VA[i].toStdString() << ":";
		auto first = g.HL[i]->begin();
		auto last = g.HL[i]->end();
		for (; first != last; ++first)
		{
			ostr << "(" << (*first).dest << "," << (*first).deptime.toString().toStdString() << "," 
				<< (*first).timecost.toString().toStdString() << "," << (*first).discost << "," << (*first).uuid.toStdString() << ","
				<< (*first).type << "," << (*first).price
				<< ")"
				<< " ";

			//output the data
			qDebug() <<"(" << (*first).dest << "," << (*first).deptime.toString() << ","
				<< (*first).timecost.toString() << "," << (*first).discost << "," << (*first).uuid << ","
				<< (*first).type << "," << (*first).price
				<< ")"
				<< " "<<endl;
		}
		ostr << endl;
	}
	return ostr;
}



bool Graph::deleteE(const QString &v1, const QString &v2, const QString &uuid){
	int si = find_node(v1);
	int dj = find_node(v2);
	if (si == -1 || dj == -1)
	{
		return false;
	}

	auto first = HL[si]->begin();
	auto last = HL[si]->end();
	for (; first != last; ++first)
	{
		if ((*first).uuid == uuid)
		{
			HL[si]->erase(first);
			sizeE--;
			return true;
		}
	}
	return false;
}

QList<EdgeNode>::iterator Graph::findrecord(const QString &v1, const QString &v2, const QString &uuid){
	QList<EdgeNode>::iterator *empty= new QList<EdgeNode>::iterator(nullptr);
	int si = find_node(v1);
	int dj = find_node(v2);
	if (si == -1 || dj == -1)
	{
		return *empty;
	}
	auto first = HL[si]->begin();
	auto last = HL[si]->end();
	for (; first != last; ++first)
	{
		if ((*first).uuid == uuid)
		{
			qDebug() << "successful!";
			return first;
		}
	}
	return *empty;
	
}


bool Graph::deleteV(const QString &v)
{
	int si = find_node(v);
	if (si == -1)
	{
		return false;
	}
	int size = HL[si]->size();
	delete HL[si];

	VA.erase(VA.begin() + si);
	HL.erase(HL.begin() + si);
	sizeE -= size;

	for (int i = 0; i < VA.size(); ++i)
	{
		QList<EdgeNode>::iterator first = HL[i]->begin();
		QList<EdgeNode>::iterator last = HL[i]->end();
		for (; first != last; first++)
		{
			if ((*first).dest == si)
			{
				HL[i]->erase(first);
				sizeE--;
			}
		}
	}

	for (int i = 0; i < VA.size(); i++)
	{
		auto first = HL[i]->begin();
		auto last = HL[i]->end();
		if ((*first).dest > si)
		{
			(*first).dest = (*first).dest-1;
		}
	}
	return true;
}

int Graph::getEdgeNum(int index){
	int sizeEdge = 0;
	auto first = HL[index]->begin();
	auto last = HL[index]->end();
	for (; first != last;first++)
	{
		sizeEdge++;
	}
	return sizeEdge;
}
vector<PathData> Graph::dijkstra(const QString &v, vector<double>& D, vector<int>& P){
	PathData item;
	vector<PathData> E;
	double cost;
	QString transID;
	isStart = true;
	int s = find_node(v);
	if (s == -1){ return E; }

	D[s] = 0;
	P[s] = -1;
	for (int i = 0; i < VA.size(); ++i){
		if (s == i){ continue; }

		item.start = s;
		item.dest = i;
		item.cost = get_cost(s, i, transID);
		item.uuid = transID;
		E.push_back(item);
		D[i] = item.cost;
		P[i] = cost == MAXWEIGHT ? -1 : s;
	}

	int count = 0;
	BuildHeap(E, VA.size() - 1);
	for (int i = 0; i < VA.size()-1; ++i){
		if (E[0].cost < MAXWEIGHT)count++;
		int ns = E[0].dest;
		for (int j = 1; j < VA.size() - 1 - i; ++j){
			cost = get_cost(ns, E[j].dest, transID);
			if (E[j].cost > E[0].cost + cost){
				E[j].cost = E[0].cost + cost;
				E[j].start = ns;
				E[j].uuid = transID;
				D[E[j].dest] = E[j].cost;
				P[E[j].dest] = ns;
			}
		}

		item = E[0];
		E[0] = E[VA.size() - i - 2];
		E[VA.size() - i - 2] = item;
		BuildHeap(E, VA.size() - i - 2);
	}
	return E;
}

PathData getuuidfromvec(vector<PathData>& res, int s, int d){
	for (int i = 0; i < res.size(); i++){
		if (res[i].start == s&&res[i].dest == d){
			return res[i];
		}
	}
	return PathData();
}

vector<PathData> Graph::get_solution(QString s, QString l){
	vector<PathData> uuid;
	vector<double> D(100000);
	vector<int> P(100000);
	vector<PathData> result;
	result=dijkstra(s, D, P);
	if (result.empty()){
		return uuid;
	}
	int si = find_node(s);
	int li = find_node(l);
	if (si == -1 || li == -1){
		return uuid;
	}

	bool reachable = false;
	while (P[li] != -1){
		if (D[li] >= MAXWEIGHT - 10){
			break;
		}
		if (P[li] == si){
			reachable = true;
			break;
		}
		li = P[li];
	}

	if (reachable){
		PathData temp;
		li = find_node(l);
		int next = P[li];
		while (true){
			temp = getuuidfromvec(result,next, li);
			uuid.push_back(temp);
			if (next == si)break;
			li = next;
			next = P[next];
		}
		return uuid;
	}
	else{
		return uuid;
	}

}

double Graph::get_cost(int s, int j, QString &transID){
	//根据不同的选择,设置权值的返回策略；
	double cost = MAXWEIGHT;
	QTime MAXTime(23, 59, 59, 59);
	QTime timecost(23, 59, 59, 59);//给QTime一个极大值
	QTime starttime;
	QTime TwoHour(2, 0, 0, 0);

	auto first = HL[s]->begin();
	auto end = HL[s]->end();
	for (; first != end; first++){
		if (Priority == 0){
			if (TrafficMode == 0){
				if (first->dest == j && first->type==0 && first->price<cost){
					cost = first->price;
					transID = first->uuid;
				}
			}
			else{
				if (first->dest == j && first->type == 1 && first->price<cost){
					cost = first->price;
					transID = first->uuid;
				}
			}
		}
		else
		{
			if (TrafficMode == 0){
				//如果是起点
				if (isStart){
					if (first->dest == j && first->type == 0)
					{
						if (first->timecost < timecost)
						{
							timecost = first->timecost;
							starttime = first->deptime;
							transID = first->uuid;
						}
					}
				}
				//如果不是起点
				else{
					if (first->dest == j&& first->type == 0){
						//判断是否满足出发时间小于到达+换乘时间
						if (arrvialTime.addMSecs(TwoHour.msecsSinceStartOfDay())<first->deptime)
						{
							if (first->timecost < timecost)
							{
								timecost = first->timecost;
								starttime = first->deptime;
								transID = first->uuid;
							}
						}

					}
				}
			}
			else{
				//如果是起点
				if (isStart){
					if (first->dest == j && first->type == 1)
					{
						if (first->timecost < timecost)
						{
							timecost = first->timecost;
							starttime = first->deptime;
							transID = first->uuid;
						}
					}
				}
				//如果不是起点
				else{
					if (first->dest == j&& first->type == 1){
						//判断是否满足出发时间小于到达+换乘时间
						if (arrvialTime.addMSecs(TwoHour.msecsSinceStartOfDay())<first->deptime)
						{
							if (first->timecost < timecost)
							{
								timecost = first->timecost;
								starttime = first->deptime;
								transID = first->uuid;
							}
						}
					
					}
				}
			}
		}
	}
	isStart = false;
	if (Priority == 1 && timecost == MAXTime){
		first = HL[s]->begin();
		for (; first != end; first++){
			if (TrafficMode == 0){
				if (first->dest == j&& first->type == 0){
					timecost = first->timecost;
					starttime = first->deptime;
					transID = first->uuid;
				}
			}
			else{
				if (first->dest == j&& first->type == 1){
					timecost = first->timecost;
					starttime = first->deptime;
					transID = first->uuid;
				}
			}
			
		}
	}

	arrvialTime = starttime.addMSecs(timecost.msecsSinceStartOfDay());

	if (Priority == 0){
		return cost;
	}
	else{
		return timecost.msecsSinceStartOfDay();
	}
}


void Graph::BuildHeap(vector<PathData>& E, int size){
	for (int i = E.size() / 2 - 1; i >= 0; --i){
		PercolateDown(E, i, size);
	}
}


void Graph::PercolateDown(vector<PathData>& E, int pos, int size){
	int p = pos;
	int c = 2 * p + 1;
	PathData tmp = E[p];
	while (c < size){
		if (c + 1 < size && E[c + 1].cost<E[c].cost){
			++c;
		}
		if (tmp.cost < E[c].cost){
			break;
		}
		else{
			E[p] = E[c];
			p = c;
			c = 2 * p + 1;
		}
	}
	E[p] = tmp;
}

void Graph::PercolateUp(vector<PathData>& E, int pos){
	int c = pos;
	int p = (c - 1) / 2;
	PathData tmp = E[c];
	while (p >= 0){
		if (E[c].cost < E[p].cost){
			E[c] = E[p];
			c = p;
			p = (c - 1) / 2;
		}
		else{
			break;
		}
	}
	E[c] = tmp;
}
