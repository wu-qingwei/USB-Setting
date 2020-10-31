#include "usbset.h"

USBSet::USBSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(u8"USB����@wu");
	setWindowFlags(Qt::WindowCloseButtonHint);
	setFixedSize(200, 160);
	reg = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\USBSTOR", QSettings::NativeFormat);
	QObject::connect(ui.pBtn_Openusb, SIGNAL(clicked()), this, SLOT(OpenUSB()));
	QObject::connect(ui.pBtn_Closeusb, SIGNAL(clicked()), this, SLOT(CloseUSB()));
}

void USBSet::OpenUSB()
{
	reg->setValue("Start", 3);
	int key = reg->value("Start").toInt();
	QString out;
	if (key == 3)
		out = u8"USB�����ɹ�! USBSTOR/Start��ֵΪ 3";
	else
		out = u8"USB����ʧ��! USBSTOR/Start��ֵΪ" + QString::number(key) + u8".���Թ���Ա�����������.";
	ui.plainTextEdit->setPlainText(out);
}

void USBSet::CloseUSB()
{
	reg->setValue("Start", 4);
	int key = reg->value("Start").toInt();
	QString out;
	if (key == 4)
		out = u8"USB�رճɹ�! USBSTOR/Start��ֵΪ 4";
	else
		out = u8"USB����ʧ��! USBSTOR/Start��ֵΪ" + QString::number(key) + u8".���Թ���Ա�����������.";
	ui.plainTextEdit->setPlainText(out);
}
