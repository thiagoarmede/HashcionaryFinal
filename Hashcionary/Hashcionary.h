#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Hashcionary.h"

class Hashcionary : public QMainWindow
{
	Q_OBJECT

public:
	Hashcionary(QWidget *parent = Q_NULLPTR);
	void on_botaoBuscar_clicked();

private:
	Ui::HashcionaryClass ui;
};
