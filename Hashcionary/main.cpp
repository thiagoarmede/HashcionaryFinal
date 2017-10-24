#include "Hashcionary.h"
#include <QtWidgets/QApplication>
#include "palavra.h"
#include "Hashing.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <cstdio>
#include <ui_JanelaInsercao.h>

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

/*
	Caso a função retorne -3, tabela inexistente.
	Caso a função retorne -2, tabela cheia.
	Caso a função retorne -1, chave repetida.
*/

/*
	Função retornará NULL caso não seja possivel recuperar o elemento da tabela
	ou, não haja o elemento na tabela.
*/

/*
Palavra* recuperaRegistro(string pal, FILE *fp) {
	Palavra *retorno = new Palavra();
	int posicao = buscaRegistro(pal, fp);
	
	if (posicao < 0)return NULL;
	if (!fp) return NULL; //tabela inexistente, arquivo invalido.
	
	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fread(retorno, sizeof(Palavra), 1, fp);
	
	return retorno;
}
*/
/*
bool eliminaRegistro(string pal, FILE *fp) {
	Palavra *eliminar = new Palavra();
	int posicao = buscaRegistro(pal, fp);

	if (!fp) return false; //tabela inexistente, arquivo invalido.
	if (posicao < 0)return false;

	fseek(fp, posicao * sizeof(Palavra), SEEK_SET);
	fread(eliminar, sizeof(Palavra), 1, fp);

	eliminar->setExistente(false);

	return true;
}
*/


////////////////função em stand-by/////////////
/*string listaArquivo(FILE *fp) {
	if (!fp)return;
	
	rewind(fp);

	while (!feof(fp))
	{

	}
}*/

void preencheArquivo(FILE *fp) {
	Palavra *pal = new Palavra();
	fp = fopen("Tabela.bin", "wb+");

	for (int i = 0; i < TAM_TABELA; i++) {
		fwrite(pal, sizeof(Palavra), 1, fp);
	}

	fclose(fp);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	QApplication a(argc, argv);
	Hashcionary w;
	JanelaInsercao *ji = new JanelaInsercao(NULL);
	JanelaLista *jl = new JanelaLista(NULL);
	preencheArquivo(fp);

	//sinaiS

	w.setJanelaInsercao(ji);
	w.setJanelaLista(jl);
	w.show();

	return a.exec();
}
