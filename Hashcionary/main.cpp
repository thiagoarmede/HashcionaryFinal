#include "Hashcionary.h"
#include <QtWidgets/QApplication>
#include "palavra.h"
#include <QApplication>
#define TAM_TABELA 97
#define MAIOR_PRIMO 89
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

/*
int funcaoHash1(Palavra pal){
int valor = 0;
int prioridade;

for(int i=0; i<pal.chave.size(); i++){
prioridade = pal.chave.size() - i;
valor = valor + (pal.chave[i] * prioridade);
}

return valor % TAM_TABELA;
}*/


int funcaoHash1(Palavra* pal){
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


int funcaoHash2(Palavra *pal) {
	int valor = 0;

	for (int i = 0; i<pal->getChave().size(); i++) {
		valor += pal->getChave()[i];
	}

	return MAIOR_PRIMO - (valor % MAIOR_PRIMO);
}


/*
	Caso a função retorne -3, tabela inexistente.
	Caso a função retorne -2, tabela cheia.
	Caso a função retorne -1, chave repetida.
*/



int insereArquivo(Palavra *pal, FILE *fp) {
	int pos1 = funcaoHash1(pal);
	int pos2;
	int contador;
	Palavra *aux;

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
	}else{
		pos2 = pos1 + funcaoHash2(pal);
		if (pos2 >= 97) {
			pos2 = pos2 - 96;
		}
		contador = 2;
		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
		fread(aux, sizeof(Palavra), 1, fp);

		while (aux->getExistente() == true){
			if (pos2 == pos1) 
				return -2;
			if (aux->getChave() == pal->getChave())
				return -1;
			pos2 += funcaoHash2(pal);
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
	bool feito;
	Palavra *aux2, *aux3;
	int posaux1, posaux2;

	while (i + j < contador && !feito) {
		//lendo posição i
		if (i == 1) {
			fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}else{
			fseek(fp, pos1 + (j * sizeof(Palavra)), SEEK_SET);
			fread(aux2, sizeof(Palavra), 1, fp);
		}
		
		fseek(fp, -sizeof(Palavra), SEEK_CUR);
		
		if (j == 1)
			posaux2 = funcaoHash1(aux2);
		else
			posaux2 += (j*funcaoHash2(aux2));
		if (posaux2 >= 97)
			posaux2 = posaux2 - 96;

		fseek(fp, posaux2 * sizeof(Palavra), SEEK_SET);
		fread(aux3, sizeof(Palavra), 1, fp);

		if (aux3->getExistente() == false){
			fseek(fp, -sizeof(Palavra), SEEK_CUR);
			fwrite(aux2, sizeof(Palavra), 1, fp);
			fseek(fp, posaux2 * sizeof(Palavra), SEEK_SET);
			fwrite(pal, sizeof(Palavra), 1, fp);
			return posaux2;
		}else{
			if (i == j)
				i++;
			else
				j++;
		}
	}
}


/*
	Função retornará NULL caso não seja possivel recuperar o elemento da tabela
	ou, não haja o elemento na tabela.
*/

int buscaRegistro(string pal, FILE *fp) {
	int pos1, pos2, contador, deslocamento;
	Palavra *aux, *palRecupera, *palRetorno;

	if (!fp) {
		return -3; //tabela inexistente, arquivo invalido
	}

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
	
Palavra* recuperaRegistro(string pal, FILE *fp) {
	Palavra *retorno;
	int posicao = buscaRegistro(pal, fp);
	
	if (posicao < 0)return NULL;
	if (!fp) return NULL; //tabela inexistente, arquivo invalido.
	
	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fread(retorno, sizeof(Palavra), 1, fp);
	
	return retorno;
}

bool eliminaRegistro(string pal, FILE *fp) {
	Palavra *eliminar;
	int posicao = buscaRegistro(pal, fp);

	if (!fp) return false; //tabela inexistente, arquivo invalido.
	if (posicao < 0)return false;

	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fread(eliminar, sizeof(Palavra), 1, fp);

	eliminar->setExistente(false);

	return true;
}

////////////////função em stand-by/////////////
/*string listaArquivo(FILE *fp) {
	if (!fp)return;
	
	rewind(fp);

	while (!feof(fp))
	{

	}
}*/


	/*
	if (!fp) {
		return NULL; //tabela inexistente, arquivo invalido
	}

	fseek(fp, pos1 * sizeof(Palavra), SEEK_SET);
	fread(aux, sizeof(Palavra), 1, fp);

	//Hashing Duplo
	if ((aux->getExistente() == true) && (aux->getChave() == pal)) {
		fseek(fp, -sizeof(Palavra), SEEK_CUR);
		fread(palRetorno, sizeof(Palavra), 1, fp);
		return palRetorno;
	}
	else {
		pos2 = pos1 + funcaoHash2(palRecupera);
		if (pos2 >= 97) {
			pos2 = pos2 - 96;
		}
		contador = 2;

		fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
		fread(aux, sizeof(Palavra), 1, fp);

		while (aux->getExistente() == true) {
			if (pos2 == pos1)
				return NULL;
			if (aux->getChave() == pal)
				return aux;
			pos2 += funcaoHash2(palRecupera);
			if (pos2 >= 97) {
				pos2 = pos2 - 96;
			}
			fseek(fp, pos2 * sizeof(Palavra), SEEK_SET);
			fread(aux, sizeof(Palavra), 1, fp);
			contador++;
		}
	}
	*/


//void Hashcionary::on_botaoBuscar_clicked() {
	//about(this, "Teste","teste");
//}


int main(int argc, char *argv[])
{
	FILE *fd1;
	fd1 = fopen("Tabela.bin", "ab+");

	QApplication a(argc, argv);
	Hashcionary w;
	w.show();

	return a.exec();
}
