#include "Palavra.h"

//Construtores

Palavra::Palavra(string palavra, string significado) {
	this->chave = palavra;
	this->significado = significado;
	this->existente = true;
}

Palavra::Palavra(string palavra) {
	this->chave = palavra;
	this->significado = "----------------------------------------------";
	this->existente = true;
}

Palavra::Palavra()
{
	this->existente = false;
	this->chave = "----------------------------------------------";
	this->significado = "----------------------------------------------";
}

Palavra::~Palavra()
{
}

//Getters e setters

string Palavra::getChave() {
	return this->chave;
}

string Palavra::getSignificado() {
	return this->significado;
}

bool Palavra::getExistente() {
	return this->existente;
}

void Palavra::setExistente(bool exis) {
	this->existente = exis;
}

void Palavra::setPalavra(string pal) {
	this->chave = pal;
}

void Palavra::setSignificado(string sig) {
	this->significado = sig;
}

//Funções pra inserção da palavra no arquivo

