#pragma once
#include "Entry.h"
#include <string.h>
#include <iostream>

using namespace std;

class StringData : public Entry
{
private:
	string value;
public:
	StringData(string name, string value);
	void Add(string toAdd) override;
	bool Substract(int toSubstract) override;
	void Print() override;
};

