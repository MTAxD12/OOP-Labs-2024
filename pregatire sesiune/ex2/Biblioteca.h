#pragma once
#include "Carte.h"
#include <vector>
#include <functional>
#include <iostream>
class Biblioteca
{
private:
	int count;
	vector<Carte*> carti;
public:
	Biblioteca();
	~Biblioteca();
	Biblioteca& operator+= (Carte *c);
	vector<Carte*>::iterator begin();
	vector<Carte*>::iterator end();
	operator int();
	void PrintFilter(function<bool(Carte*) > fn);
};

