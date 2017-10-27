#include "Hashcionary.h"
#include <QtWidgets/QApplication>
#include "palavra.h"
#include "Hashing.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <cstdio>
#include <ui_JanelaInsercao.h>


int main(int argc, char *argv[])
{
	//FILE *fp;
	QApplication a(argc, argv);
	Hashcionary w;
	//preencheArquivo(fp);
	//fp = fopen("Tabela.bin", "rb+");

	w.show();
	return a.exec();
}
