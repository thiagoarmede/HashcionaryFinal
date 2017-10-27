#include "Hashing.h"

Hashing::Hashing()
{
}
  
Hashing::~Hashing()
{
}

int Hashing::funcaoHash1(Palavra* pal) {
	int tamChave = pal->getChave().size() / 4;
	long soma = 0;

	for (int i = 0; i<tamChave; i++) {
		string aux = pal->getChave().substr(i * 4, (i * 4) + 4);
		long multi = 1;

		for (int j = 0; j<aux.size(); j++) {
			soma += aux[j] * multi;
			multi *= 256;
		}
	}

	if (pal->getChave().size() < 4) {
		long multi = 1;

		for (int k = 0; k < pal->getChave().size(); k++) {
			soma += pal->getChave()[k] * multi;
			multi *= 256;
		}
	}

	return abs(soma) % TAM_TABELA;
}

int Hashing::funcaoHash2(Palavra *pal) {
	int valor = 0;

	for (int i = 0; i<pal->getChave().size(); i++) {
		valor += pal->getChave()[i];
	}

	return MAIOR_PRIMO - (valor % MAIOR_PRIMO);
}

int Hashing::buscaRegistro(string pal, FILE *fp, int *count) {
	Hashing *h = new Hashing();
	int pos1;
	int pos2;
	int contador = 1;
	Palavra *aux = new Palavra();
	Palavra *palRetorna = new Palavra(pal);

	/*
	Função retornará -3 caso o arquivo não exista ou não esteja aberto.
	Função retornará -1 caso o elemento nao exista na tabela
	*/
	pos1 = h->funcaoHash1(palRetorna);

	if (!fp) {
		return -3; //tabela inexistente, arquivo invalido
	}

	//leitura do arquivo após o primeiro hashing.

	fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
	fread(aux, sizeof(Palavra), 1, fp);

	//consulta se posição está vazia para inserção

	if (aux->getChave() == pal) {
		*count = contador =  1;
		return pos1;
	}
	else {		//Segundo hashing caso a primeira posição não esteja vazia
		pos2 = (pos1 + h->funcaoHash2(palRetorna)) % TAM_TABELA;
		//contador = 2;
		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);

		while (aux->getExistente() == true) {
			if (pos2 == pos1)
				return -1;
			if (aux->getChave() == palRetorna->getChave())
				return pos2;
			*count = ++contador;
			fread(aux, sizeof(Palavra), 1, fp);
			pos2 = (pos2 + h->funcaoHash2(palRetorna)) % TAM_TABELA;

			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux, sizeof(Palavra), 1, fp);

		}
	}

	return -1;
}

