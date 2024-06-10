#include "IntegerData.h"

IntegerData::IntegerData(string name, string value) : Entry(name)
{
	this->name = name;
	this->value = atoi(value.c_str());
}

void IntegerData::Add(string toAdd)
{
	this->value += atoi(toAdd.c_str());
}

bool IntegerData::Substract(int toSubstract)
{
	this->value -= toSubstract;
	return true;
}

void IntegerData::Print()
{
	cout << this->name << " = " << this->value << ";";
}
