#include "Revista.h"

Revista::Revista(string titlu, int nrArticole)
{
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}

string Revista::GetInfo()
{
	string aux;
	aux = "Revista ";
	aux += titlu;
	aux += " cu ";
	aux += to_string(nrArticole);
	aux += " articole";
	return aux;
}
