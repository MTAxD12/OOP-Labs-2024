#include "Movie.h"
#include <fstream>

Movie::Movie()
{
	strcpy_s(numeFilm, "");
	anLansare = 0;
	imbd = 0.0f;
	durata = 0;
}

void Movie::SetareNume(char* nume)
{
	strcpy_s(numeFilm, nume);
}

char* Movie::GetNume()
{
	return numeFilm;
}

void Movie::SetareAnLansare(int an)
{
	anLansare = an;
}

int Movie::GetAnLansare()
{
	return anLansare;
}

void Movie::SetareIMBD(float scor)
{
	imbd = scor;
}

float Movie::GetIMBD()
{
	return imbd;
}

void Movie::SetareDurata(int minute)
{
	durata = minute;
}

int Movie::GetDurata()
{
	return durata;
}

int Movie::GetAniTrecuti()
{
	return 2024 - anLansare;
}
