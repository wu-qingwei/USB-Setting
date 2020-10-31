#include "usbset.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	USBSet w;
	w.show();
	return a.exec();
}
