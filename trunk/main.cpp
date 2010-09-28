#include "qm4c.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QM4C w;
	w.show();
	return a.exec();
}
