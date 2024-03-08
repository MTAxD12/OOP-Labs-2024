#pragma once
#include "Movie.h"
class MovieSeries
{
	int count;
	Movie* filme[10];
public:
	void Init();
	void AddFilm(Movie *film);
	void PrintFilme();
	void SortFilme();
};

