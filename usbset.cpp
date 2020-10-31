#include "usbset.h"

USBSet::USBSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(u8"USB设置@wu");
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
		out = u8"USB开启成功! USBSTOR/Start键值为 3";
	else
		out = u8"USB开启失败! USBSTOR/Start键值为" + QString::number(key) + u8".请以管理员身份重新运行.";
	ui.plainTextEdit->setPlainText(out);
}

void USBSet::CloseUSB()
{
	reg->setValue("Start", 4);
	int key = reg->value("Start").toInt();
	QString out;
	if (key == 4)
		out = u8"USB关闭成功! USBSTOR/Start键值为 4";
	else
		out = u8"USB开启失败! USBSTOR/Start键值为" + QString::number(key) + u8".请以管理员身份重新运行.";
	ui.plainTextEdit->setPlainText(out);
}
