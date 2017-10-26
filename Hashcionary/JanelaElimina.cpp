#include "JanelaElimina.h"

JanelaElimina::JanelaElimina(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	popup = new popup1();
	QObject::connect(ui.botaoElimina, SIGNAL(clicked()), this, SLOT(eliminaPalavra()));
}

JanelaElimina::~JanelaElimina()
{
}

void JanelaElimina::eliminaPalavra() {
	Hashing *h = new Hashing();
	Palavra *eliminar = new Palavra();
	string pal = ui.linhaElimina->text().toStdString();
	int count = 0;
	FILE *fp;

	fp = fopen("Tabela.bin", "rb+");

	int posicao = h->buscaRegistro(pal, fp, &count);

	if (!fp) return; //tabela inexistente, arquivo invalido.
	if (posicao < 0)return;

	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);

	eliminar->setExistente(false);
	eliminar->setPalavra("INEXISTENTE");
	eliminar->setSignificado("INEXISTENTE");

	fwrite(eliminar, sizeof(Palavra), 1, fp);
	fclose(fp);

	popupEliminou();
}

void JanelaElimina::popupEliminou() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Palavra Eliminada!");
	ui.linhaElimina->clear();
	popup->show();
};