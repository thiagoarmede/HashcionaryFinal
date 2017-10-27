#pragma once
#include <QWidget>
#include "ui_JanelaLista.h"
#include "Palavra.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#define TAM_TABELA 97
#define MAIOR_PRIMO 89

class JanelaLista : public QWidget
{
	Q_OBJECT

public:
	JanelaLista(QWidget *parent = Q_NULLPTR);
	~JanelaLista();


public slots:
	void listaPalavras();

private:
	Ui::JanelaLista ui;
	Palavra *pal;
};
