#include "FenClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FenClient w;
	w.show();
	return a.exec();
}
