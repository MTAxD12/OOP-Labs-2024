#pragma once
#include "Procesator.h"
#include <functional>
#include <iostream>

using namespace std;

class Find : public Procesator
{
private:
	function<bool(int)> fnc;
public:
	Find(function<bool(int)> fnc);
	void Run(int* a, int count) override;

};

