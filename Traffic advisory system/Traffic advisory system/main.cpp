/*
*	The Traffic Advisory System
*
*	Copyright (c) 2019 WangTao <wangtao@fretory.cn>
*
*	Can be freely distributed and used under the terms of the GNU GPL.
*	
*   Sorry for my confused code :)
*
*/


#include "trafficadvisorysystem.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Trafficadvisorysystem w;
	w.setWindowIcon(QIcon(":/Trafficadvisorysystem/pics/icon.png"));
	w.show();
	return a.exec();
}
