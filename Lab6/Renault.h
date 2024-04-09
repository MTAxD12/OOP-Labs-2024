#pragma once
#include "Car.h"

class Renault : public Car
{
public:
	Renault();
	double timpParcurs(double lungime, Weather vreme) const override;

	void setTimes(bool finished, int secunde);

	std::string getNume() const override { return "Renault"; }
};

