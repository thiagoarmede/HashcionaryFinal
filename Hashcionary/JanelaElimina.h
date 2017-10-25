#pragma once

#include <QWidget>
#include "ui_JanelaElimina.h"

class JanelaElimina : public QWidget
{
	Q_OBJECT

public:
	JanelaElimina(QWidget *parent = Q_NULLPTR);
	~JanelaElimina();

private:
	Ui::JanelaElimina ui;
};
