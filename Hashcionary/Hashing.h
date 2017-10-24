#pragma once
#define TAM_TABELA 97
#define MAIOR_PRIMO 89
#include "Palavra.h"

static class Hashing
{
public:
	Hashing();
	~Hashing();
	int funcaoHash1(Palavra *);
	int funcaoHash2(Palavra *);
	int buscaRegistro(string, FILE*);
};

