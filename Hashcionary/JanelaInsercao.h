#pragma once
#include <QWidget>
#include "ui_JanelaInsercao.h"
#include <string>
#include <iostream>
#include "Palavra.h"
#include "Hashing.h"

using namespace std;

class JanelaInsercao : public QWidget
{
	Q_OBJECT

public:
	JanelaInsercao(QWidget *parent = Q_NULLPTR);
	~JanelaInsercao();
	QString getPalavra();
	QString getSignificado();
	//funções para inserção da palavra
	int defineInsercao(Palavra *, FILE *);
public slots:
	void inserePalavra();
private:
	Ui::JanelaInsercao ui;
};
