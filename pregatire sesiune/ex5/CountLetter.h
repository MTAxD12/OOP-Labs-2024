#pragma once
#include "Procesor.h"
#include <functional>
class CountLetter : public Procesor
{
private:
	string nume;
	function<bool(char)> fnc;
public:
	CountLetter(string nume, function<bool(char)> fnc);
	string GetName() override;
	int Compute(string prop) override;
};

