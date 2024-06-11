#include "CountLetter.h"

CountLetter::CountLetter(string nume, function<bool(char)> fnc)
{
	this->nume = nume;
	this->fnc = fnc;
}

string CountLetter::GetName()
{
	return this->nume;
}

int CountLetter::Compute(string prop)
{
	int count = 0;
	for (int i = 0; i <= prop.size(); i++)
		if (this->fnc(prop[i]))
			count++;
	return count;
}
