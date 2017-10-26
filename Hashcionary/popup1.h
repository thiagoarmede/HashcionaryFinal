#pragma once

#include <QWidget>
#include "ui_popup1.h"

class popup1 : public QWidget
{
	Q_OBJECT

public:
	popup1(QWidget *parent = Q_NULLPTR);
	~popup1();

private:
	Ui::popup1 ui;
};
