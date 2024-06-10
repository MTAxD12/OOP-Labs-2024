#include "StringData.h"

StringData::StringData(string name, string value) : Entry(name)
{
	this->name = name;
	this->value = value;
}

void StringData::Add(string toAdd)
{
	this->value += toAdd;
}

bool StringData::Substract(int toSubstract)
{
	if (toSubstract > this->value.size())
	{
		cout << "StringData: len(" << this->name << ") < " << toSubstract << "\n";
		return false;
	}
	else
	{
		this->value.erase(value.size() - toSubstract, toSubstract);
		return true;
	}
}

void StringData::Print()
{
	cout << this->name << " = " << this->value << ";";
}
