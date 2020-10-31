#pragma once

#include <QtWidgets/QWidget>
#include <QtCore/qsettings.h>
#include <QtCore/qdebug.h>
#include <QtCore/qstring.h>
#include <QtWidgets/qstatusbar.h>

#include "ui_usbset.h"

class USBSet : public QWidget
{
	Q_OBJECT

public:
	USBSet(QWidget *parent = Q_NULLPTR);

private slots:
	void OpenUSB();
	void CloseUSB();

private:
	Ui::USBSetClass ui;
	QSettings *reg;
};
