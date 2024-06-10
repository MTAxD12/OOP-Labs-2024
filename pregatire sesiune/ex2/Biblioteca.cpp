#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
	this->count = 0;
}

Biblioteca::~Biblioteca()
{
	for (Carte* carte : carti)
		delete carte;
	carti.clear();
}

Biblioteca& Biblioteca::operator+=(Carte* c)
{
	carti.push_back(c);
	count++;
	return *this;
}

vector<Carte*>::iterator Biblioteca::begin()
{
	return this->carti.begin();
}

vector<Carte*>::iterator Biblioteca::end()
{
	return this->carti.end();
}

Biblioteca::operator int()
{
	return count;
}

void Biblioteca::PrintFilter(function<bool(Carte*)> fn)
{
	for (auto it : carti)
		if (it->GetInfo()[1] == 'o') {
			cout << it->GetInfo() << endl;
		}
}
