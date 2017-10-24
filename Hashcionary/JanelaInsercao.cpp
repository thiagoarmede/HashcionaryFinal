#include "JanelaInsercao.h"


JanelaInsercao::JanelaInsercao(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.InsereBotaoInserir, SIGNAL(clicked()), this, SLOT(inserePalavra()));
}

JanelaInsercao::~JanelaInsercao()
{
}


//Getters e Setters

QString JanelaInsercao::getPalavra() {
	return ui.InsereLinhaPalavra->text();
}

QString JanelaInsercao::getSignificado() {
	return ui.InsereMostraTexto->toPlainText();
}

//Funções para inserção da palavra

int JanelaInsercao::defineInsercao(Palavra* pal, FILE *fp) {
	Hashing *h = new Hashing();
	int pos1 = h->funcaoHash1(pal);
	int pos2;
	int contador;
	Palavra *aux = new Palavra();

	if (!fp) {
		return -3; //tabela inexistente, arquivo invalido
	}

	fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
	fread(aux, sizeof(Palavra), 1, fp);

	//Hashing Duplo
	if (aux->getExistente() != true) {
		fseek(fp, -sizeof(Palavra), SEEK_CUR);
		fwrite(pal, sizeof(Palavra), 1, fp);
		return pos1;
	}
	else {
		pos2 = pos1 + h->funcaoHash2(pal);
		if (pos2 >= 97) {
			pos2 = pos2 - 96;
		}
		contador = 2;

		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
		fread(aux, sizeof(Palavra), 1, fp);

		while (aux->getExistente() == true) {
			if (pos2 == pos1)
				return -2;
			if (aux->getChave() == pal->getChave())
				return -1;
			pos2 += h->funcaoHash2(pal);
			if (pos2 >= 97) {
				pos2 = pos2 - 96;
			}
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux, sizeof(Palavra), 1, fp);
			contador++;
		}
	}
	//Método de Brent
	int i = 1, j = 1;
	bool feito = false;
	Palavra *aux2, *aux3;
	int posaux1, posaux2;

	aux2 = new Palavra();
	aux3 = new Palavra();

	while (i + j < contador && !feito) {
		//lendo posição i
		if (i == 1) {
			fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}
		else {
			fseek(fp, pos1 + (j * sizeof(Palavra)), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}

		fseek(fp, -sizeof(Palavra), SEEK_CUR);

		if (j == 1)
			posaux2 = h->funcaoHash1(aux2);
		else
			posaux2 += (j * h->funcaoHash2(aux2));
		if (posaux2 >= 97)
			posaux2 = posaux2 - 96;

		fseek(fp, posaux2 * sizeof(Palavra), SEEK_SET);
		fread(aux3, sizeof(Palavra), 1, fp);

		if (aux3->getExistente() == false) {
			fseek(fp, -sizeof(Palavra), SEEK_CUR);
			fwrite(aux2, sizeof(Palavra), 1, fp);
			fseek(fp, posaux2 * sizeof(Palavra), SEEK_SET);
			fwrite(pal, sizeof(Palavra), 1, fp);
			return posaux2;
		}
		else {
			if (i + j == (contador - 1)) {
				i++;
				j = 1;
			}
			else {
				j++;
			}
		}
	}

	return posaux2;
}

void JanelaInsercao::inserePalavra(){
	Palavra *palavraAInserir = new Palavra(this->getPalavra().toStdString(), this->getSignificado().toStdString());
	FILE *fd1;
	fd1 = fopen("Tabela.bin", "rb+");

	int posicao = this->defineInsercao(palavraAInserir, fd1);

	if (posicao < 0) {
		std::cout << "problema na insercao" << endl;
		return;
	}

	std::cout << posicao;

	fseek(fd1, posicao * sizeof(Palavra), SEEK_SET);
	fwrite(palavraAInserir, sizeof(Palavra), 1, fd1);

	delete(palavraAInserir);
	fclose(fd1);
}