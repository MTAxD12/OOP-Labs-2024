#include "ComputeVowals.h"

ComputeVowals::ComputeVowals(string nume)
{
	this->nume = nume;
}

string ComputeVowals::GetName()
{
	return this->nume;
}

int ComputeVowals::Compute(string prop)
{
	int nr = 0;
	for (int i = 0; i < prop.size(); i++)
		if (prop[i] == 'a' || prop[i] == 'A' || prop[i] == 'e' || prop[i] == 'E' ||
			prop[i] == 'i' || prop[i] == 'I' || prop[i] == 'o' || prop[i] == 'O' ||
			prop[i] == 'u' || prop[i] == 'U')
			nr++;

	return nr;
}
