#include "LongestWord.h"

LongestWord::LongestWord(string nume)
{
	this->nume = nume;
}

string LongestWord::GetName()
{
	return this->nume;
}

int LongestWord::Compute(string prop)
{
	int longest = 0, lgCrt = 0;
	for (int i = 0; i < prop.size(); i++)
	{
		if (prop[i] == ' ')
		{
			if (lgCrt > longest)
				longest = lgCrt;
			lgCrt = 0;
		}
		else
		{
			lgCrt++;
		}
	}
	return longest;
}
