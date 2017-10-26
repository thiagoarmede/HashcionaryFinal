#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Hashcionary.h"
#include "JanelaInsercao.h"
#include "JanelaLista.h"
#include "JanelaElimina.h"
#include "Hashing.h"
#include "popup1.h"

class Hashcionary : public QMainWindow
{
	Q_OBJECT

public:
	Hashcionary(QWidget *parent = Q_NULLPTR);
	void setJanelaInsercao(JanelaInsercao *);
	void setJanelaLista(JanelaLista *);
	void recuperaRegistro();
	void popupAchou();
	popup1 *popup;
public slots:
	void on_botaoBuscar_clicked();
	void abreInsercao();
	void abreLista();
	void saiPrograma();
	void abreExclusao();
private:
	Ui::HashcionaryClass ui;
	JanelaInsercao *janelaInsercao;
	JanelaLista *janelaLista;
	JanelaElimina *janelaElimina;
};
