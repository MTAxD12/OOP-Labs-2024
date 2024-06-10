#include "Roman.h"

Roman::Roman(string nume, string autor)
{
	this->nume = nume;
	this->autor = autor;
}

string Roman::GetInfo()
{
	string aux;
	aux= "Roman ";
	aux += nume;
	aux += " de ";
	aux += autor;
	return aux;
}
