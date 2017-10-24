#include "Hashcionary.h"


Hashcionary::Hashcionary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	QObject::connect(ui.botaoBuscar, SIGNAL(clicked()), this, SLOT(on_botaoBuscar_clicked()));
	QObject::connect(ui.actionInserir_palavra, SIGNAL(triggered()), this, SLOT(abreInsercao()));
	QObject::connect(ui.actionListar_dicionario, SIGNAL(triggered()), this, SLOT(abreLista()));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(saiPrograma()));
	QObject::connect(ui.actionSair, SIGNAL(triggered()), this, SLOT(saiPrograma()));
}

//Getters e Setters

void Hashcionary::setJanelaInsercao(JanelaInsercao *jan) {
	this->janelaInsercao = jan;
}


void Hashcionary::setJanelaLista(JanelaLista *jan) {
	this->janelaLista = jan;
}


//Slots Qt

void Hashcionary::on_botaoBuscar_clicked() {
	ui.linhaBusca->setText("meu ovo");
}

void Hashcionary::abreInsercao() {
	janelaInsercao->setWindowModality(Qt::ApplicationModal);
	janelaInsercao->show();
}

void Hashcionary::abreLista() {
	janelaLista->setWindowModality(Qt::ApplicationModal);
	janelaLista->show();
}

void Hashcionary::saiPrograma() {
	this->close();
}