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

int Hashing::buscaRegistro(string pal, FILE *fp) {
	int pos1, pos2, contador, deslocamento;
	Palavra *aux, *palRecupera, *palRetorno;

	if (!fp) {
		return -3; //tabela inexistente, arquivo invalido
	}

	aux = new Palavra();
	palRecupera = new Palavra(pal);
	pos1 = funcaoHash1(palRecupera);

	fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
	fread(aux, sizeof(Palavra), 1, fp);

	//Hashing Duplo
	if (aux->getChave() == pal) {
		return pos1;
	}
	else {
		deslocamento = funcaoHash2(palRecupera);
		pos2 = pos1 + deslocamento;
		if (pos2 >= 97) {
			pos2 = pos2 - 96;
		}
		contador = 2;
		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
		fread(aux, sizeof(Palavra), 1, fp);
		while (aux->getChave() != pal) {
			contador++;
			if (pos2 == pos1) //Percorreu toda a tabela e não encontrou o registro.
				return -2;
			if (aux->getChave() == pal) //Achou o registro, retorna a posição
				return pos2;
			pos2 += deslocamento;
			if (pos2 >= 97) {
				pos2 = pos2 - 96;
			}
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux, sizeof(Palavra), 1, fp);
		}
	}
}
