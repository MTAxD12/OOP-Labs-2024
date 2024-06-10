#pragma once
#include "Entry.h"
#include <iostream>
#include <vector>

using namespace std;

class Database
{
	vector<Entry*> entries;
public:
	Database& operator+= (Entry *e);
	Database& operator-= (string name);
	vector<Entry*>::iterator begin();
	vector<Entry*>::iterator end();
	void Print();
	
};
