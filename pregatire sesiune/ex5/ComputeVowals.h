#pragma once
#include "Procesor.h"
class ComputeVowals : public Procesor
{
private:
	string nume;
public:
	ComputeVowals(string nume);
	string GetName() override;
	int Compute(string prop) override;
};

