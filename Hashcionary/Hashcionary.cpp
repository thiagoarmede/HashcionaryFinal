#include "Hashcionary.h"


Hashcionary::Hashcionary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	popup = new popup1();
	QObject::connect(ui.botaoBuscar, SIGNAL(clicked()), this, SLOT(recuperaRegistro()));
	QObject::connect(ui.actionInserir_palavra, SIGNAL(triggered()), this, SLOT(abreInsercao()));
	QObject::connect(ui.actionListar_dicionario, SIGNAL(triggered()), this, SLOT(abreLista()));
	QObject::connect(ui.actionExcluir_palavra, SIGNAL(triggered()), this, SLOT(abreExclusao()));
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

void Hashcionary::recuperaRegistro(){
	Hashing *h = new Hashing();
	Palavra *retorno = new Palavra();
	string pal = ui.linhaBusca->text().toStdString();
	string contador;
	char* buffer;
	FILE *fp;
	int count;
	fp = fopen("Tabela.bin", "rb+");


	int posicao = h->buscaRegistro(pal, fp, &count);

	if (posicao < 0) {
		popupNaoAchou();
		return;
	}
	if (!fp) return; //tabela inexistente, arquivo invalido.

	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fread(retorno, sizeof(Palavra), 1, fp);

	ui.browserSignificado->setText(QString::fromStdString(retorno->getSignificado()));

	fclose(fp);
	popupAchou();
	ui.lcdContador->display(count);
}

void Hashcionary::popupAchou() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Palavra Encontrada!");
	ui.linhaBusca->clear();
	popup->show();
}

void Hashcionary::popupNaoAchou() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Palavra Inexistente");
	ui.linhaBusca->clear();
	popup->show();
}

void Hashcionary::popupArquivoNaoEncontrado() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Arquivo não encontrado");
	ui.linhaBusca->clear();
	popup->show();
}


//Slots Qt

void Hashcionary::on_botaoBuscar_clicked() {
	//ui.linhaBusca->setText("");
}

void Hashcionary::abreInsercao() {
	janelaInsercao->setWindowModality(Qt::ApplicationModal);
	janelaInsercao->show();
}

void Hashcionary::abreLista() {
	janelaLista->setWindowModality(Qt::ApplicationModal);
	janelaLista->show();
}

void Hashcionary::abreExclusao() {
	janelaElimina = new JanelaElimina(NULL);
	janelaElimina->show();
}

void Hashcionary::saiPrograma() {
	this->close();
}