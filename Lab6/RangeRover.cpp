#include "RangeRover.h"
#include <iostream>

RangeRover::RangeRover() : Car()
{
	this->rezervor = 60;
	this->consum = 8.3;
	this->vitRain = 140;
	this->vitSnow = 130;
	this->vitSunny = 200;
}

double RangeRover::timpParcurs(double lungime, Weather vreme) const
{
	if (areBenzina(lungime)) {
		double vitMedie = 0;
		if (vreme == Weather::Sunny) vitMedie = vitSunny;
		else if (vreme == Weather::Rain) vitMedie = vitRain;
		else if (vreme == Weather::Snow) vitMedie = vitSnow;
		else printf("eroare vreme\n");

		this->finished = true;
		this->secunde = (int)(lungime * 3600 / vitMedie);

		return lungime * 3600 / vitMedie; // timpul in secunde
	}
	else
	{
		this->finished = false;
		this->secunde = 0;
		return 0.0f;
	}

}
