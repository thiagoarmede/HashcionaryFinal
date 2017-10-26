#pragma once
#include <QWidget>
#include "ui_JanelaElimina.h"
#include "Hashing.h"
#include "popup1.h"

class JanelaElimina : public QWidget
{
	Q_OBJECT

public:
	JanelaElimina(QWidget *parent = Q_NULLPTR);
	~JanelaElimina();
	popup1 *popup;
	void popupEliminou();
public slots:
	void eliminaPalavra();
private:
	Ui::JanelaElimina ui;
};
