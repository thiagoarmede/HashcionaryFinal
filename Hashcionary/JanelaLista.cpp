#include "JanelaLista.h"

JanelaLista::JanelaLista(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.botaoListar, SIGNAL(clicked()), this, SLOT(listaPalavras()));
}

JanelaLista::~JanelaLista()
{
	this->close();
	delete(ui.listaArquivo);
}


//slots

void JanelaLista::listaPalavras() {
	Palavra *aux = new Palavra();
	FILE *fd1;
	char num[5];
	string lista = "\n";
	fd1 = fopen("Tabela.bin", "rb+");

	for (int i = 0; i < TAM_TABELA; i++) {
		fread(aux, sizeof(Palavra), 1, fd1);

		lista += itoa(i, num, 10);
		lista += ": ";
		lista += aux->getChave();
		lista += "\n";
		lista += aux->getSignificado();
		lista += "\n\n";
	}

	ui.listaArquivo->setText(QString::fromStdString(lista));

	fclose(fd1);
}