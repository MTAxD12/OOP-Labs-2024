#pragma once
#include "Procesor.h"
class LongestWord : public Procesor
{
private:
	string nume;
public:
	LongestWord(string nume);
	string GetName() override;
	int Compute(string prop) override;
};

