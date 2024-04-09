#include "Renault.h"
#include <iostream>

Renault::Renault() : Car()
{
	this->rezervor = 45;
	this->consum = 5;
	this->vitRain = 220;
	this->vitSnow = 200;
	this->vitSunny = 250;
}

double Renault::timpParcurs(double lungime, Weather vreme) const
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
