#include "myclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyClock w;
	w.show();

	return a.exec();
}
