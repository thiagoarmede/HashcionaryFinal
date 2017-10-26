#include "JanelaInsercao.h"


JanelaInsercao::JanelaInsercao(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->popup = new popup1();
	QObject::connect(ui.InsereBotaoInserir, SIGNAL(clicked()), this, SLOT(inserePalavra()));
	QObject::connect(ui.InsereBotaoVoltar, SIGNAL(clicked()), this, SLOT(close()));
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

////////////////////////////////////////////////////////
////////////Fun��es para inser��o da palavra////////////
////////////////////////////////////////////////////////

int JanelaInsercao::defineInsercao(Palavra* pal, FILE *fp, int *count) {
	Hashing *h = new Hashing();
	int pos1 = h->funcaoHash1(pal);
	int pos2;
	int contador;
	Palavra *aux = new Palavra();

	/*
	Fun��o retornar� -3 caso o arquivo n�o exista ou n�o esteja aberto.
	Fun��o retornar� -2 caso a tabela esteja cheia.
	Fun��o retornar� -1 caso o elemento ja exista na tabela
	*/

	if (!fp) {
		return -3; //tabela inexistente, arquivo invalido
	}

	//leitura do arquivo ap�s o primeiro hashing.

	fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
	fread(aux, sizeof(Palavra), 1, fp);

	//consulta se posi��o est� vazia para inser��o

	if (aux->getExistente() != true) {
		fseek(fp, -sizeof(Palavra), SEEK_CUR);
		fwrite(pal, sizeof(Palavra), 1, fp);
		*count = contador = 1;
		return pos1;
	}
	else {		//Segundo hashing caso a primeira posi��o n�o esteja vazia
		pos2 = (pos1 + h->funcaoHash2(pal)) % TAM_TABELA;
		contador = 2;

		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
		while (aux->getExistente() == true) {
			if (pos2 == pos1)
				return -2;
			if (aux->getChave() == pal->getChave())
				return -1;
			
			fread(aux, sizeof(Palavra), 1, fp);
			pos2 = (pos2 + h->funcaoHash2(pal)) % TAM_TABELA;
		
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux, sizeof(Palavra), 1, fp);
			contador++;
		}
	}
	*count = contador;
	return pos2;
}


void JanelaInsercao::inserePalavra(){
	Palavra *palavraAInserir = new Palavra(this->getPalavra().toStdString(), this->getSignificado().toStdString());
	FILE *fp;
	int pos1, pos2, deslocamento, count;
	Hashing *h = new Hashing();


	pos1 = h->funcaoHash1(palavraAInserir);
	deslocamento = h->funcaoHash2(palavraAInserir);
	pos2 = pos1;

	fp = fopen("Tabela.bin", "rb+");

	int posicao = this->defineInsercao(palavraAInserir, fp, &count);

	if (posicao < 0) {
		std::cout << "problema na insercao" << endl;
		mostraPopupNaoInseriu();
		return;
	}

	std::cout << posicao;

	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fwrite(palavraAInserir, sizeof(Palavra), 1, fp);

	///////////////////////////////////////////////////////////
	//////////////////////M�todo de Brent//////////////////////
	///////////////////////////////////////////////////////////

	int i = 1, j = 1;
	Palavra *aux2, *aux3;
	int posaux, posaux2, deslocamentoAux;

	aux2 = new Palavra();
	aux3 = new Palavra();

	while (i + j < count) {
		/////////escolhendo o termo baseado no i.//////////////
		if (i == 1) {		//lendo primeiro elemento ap�s o hashing.
			fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}else{		//percorrendo arquivo e encontrando o elemento de n�mero i.
			fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
			for (int k = 1; k < i; k++) {
					pos2 = (pos2 + deslocamento) % TAM_TABELA;
			}
			//fseek(fp, pos1 *(j * sizeof(Palavra)), SEEK_SET);
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}
		
		//ap�s ler o elemento de numero i, definir o seu deslocamento.
		posaux = h->funcaoHash1(aux2);
		deslocamentoAux = h->funcaoHash2(aux2);
		posaux2 = posaux;

		///////////deslocando o termo baseado em j///////////////		
		if (j == 1) {
			fseek(fp, posaux * sizeof(Palavra), SEEK_SET);
			fread(aux3, sizeof(Palavra), 1, fp);
		}else{
			fseek(fp, posaux * sizeof(Palavra), SEEK_SET);
			for (int k = 1; k < j; k++) {
				posaux2 = (posaux2 + deslocamentoAux) % TAM_TABELA;
			}
			fseek(fp, posaux2 * sizeof(Palavra), SEEK_SET);
			fread(aux3, sizeof(Palavra), 1, fp);
		}

		if (aux3->getExistente() == false) {		//trocando posi��es dos elementos.
			fseek(fp, -sizeof(Palavra), SEEK_CUR);
			fwrite(aux2, sizeof(Palavra), 1, fp);
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fwrite(palavraAInserir, sizeof(Palavra), 1, fp);
			break;
		}else {
			if (i + j == (count)) {
				i++;
				j = 1;
			}else 
				j++;
		}


	}

	mostraPopupInseriu();
	fclose(fp);
}

void JanelaInsercao::mostraPopupInseriu() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Palavra inserida com sucesso!");
	popup->show();
	ui.InsereLinhaPalavra->clear();
	ui.InsereMostraTexto->clear();
}

void JanelaInsercao::mostraPopupNaoInseriu() {
	popup->findChild<QLabel*>("labelMensagem")->setText("Impossivel inserir!");
	popup->show();
	ui.InsereLinhaPalavra->clear();
	ui.InsereMostraTexto->clear();
}