#include "Fiat.h"
#include <iostream>

Fiat::Fiat() : Car()
{
	this->rezervor = 40;
	this->consum = 6.7;
	this->vitRain = 120;
	this->vitSnow = 100;
	this->vitSunny = 180;
}

double Fiat::timpParcurs(double lungime, Weather vreme) const
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
