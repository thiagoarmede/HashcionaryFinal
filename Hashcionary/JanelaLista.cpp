#include "JanelaLista.h"

JanelaLista::JanelaLista(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.botaoListar, SIGNAL(clicked()), this, SLOT(listaPalavras()));
}

JanelaLista::~JanelaLista()
{
	delete ui.listaArquivo;
	delete ui.botaoListar;
}


//slots

void JanelaLista::listaPalavras() {
	Palavra *aux = new Palavra();
	char num[3];
	string lista;
	fstream ifs;
	ifs.flush();
	ifs.open("Tabela.bin", fstream::binary | fstream::in | fstream::out);

	for (int i = 0; i< TAM_TABELA; i++) {
		ifs.read((char*)aux, sizeof(Palavra));		//fread(aux, sizeof(Palavra), 1, fd1);
		lista.append(itoa(i, num, 10));
		lista.append(": ");
		lista.append(aux->getChave());
		lista.append("\n");
		lista.append(aux->getSignificado());
		lista.append("\n\n");
	}

	ifs.close();
	ui.listaArquivo->setText(QString::fromStdString(lista));
}