#include "BMW.h"
#include <iostream>

BMW::BMW() : Car() 
{
	this->rezervor = 60;
	this->consum = 10;
	this->vitRain = 200;
	this->vitSnow = 180;
	this->vitSunny = 260;
}

double BMW::timpParcurs(double lungime, Weather vreme) const
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
