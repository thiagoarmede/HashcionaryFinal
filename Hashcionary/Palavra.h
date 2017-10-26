#pragma once
#include <iostream>
#include <string>

using namespace std;

class Palavra
{
public:
	Palavra(string s, string s2);
	Palavra(string s);
	~Palavra();
	Palavra();
	string getChave();
	string getSignificado();
	bool getExistente();
	void setExistente(bool);
	void setPalavra(string);
	void setSignificado(string);
private:
	string chave;
	string significado;
	bool existente;

};

