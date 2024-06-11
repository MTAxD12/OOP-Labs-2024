#pragma once
#include "Procesor.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Sentence
{
private:
	vector<Procesor*>procesators;
	string name;
public:
	Sentence(string name);
	Sentence& operator+=(Procesor* p);
	void RunAll();
	void ListAll();
	void Run(string numeFunc);
};

