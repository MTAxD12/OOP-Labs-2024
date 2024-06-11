#pragma once
#include "Procesator.h"
#include <iostream>

using namespace std;

class Suma : public Procesator
{
public:
	Suma();
	void Run(int* a, int count) override;

};

