#include "MovieSeries.h"
#include <iostream>
#include <stdio.h>

void MovieSeries::Init()
{
	count = 0;
}

void MovieSeries::AddFilm(Movie *film)
{
	if (count >= 10) {
		printf("Nu se mai pot adauga filme\n");
		return;
	}
	else
	{
		printf("\nA fost adaugat filmul: %s\n", film->GetNume());
		filme[count++] = film;
		return;
	}
}

void MovieSeries::PrintFilme()
{
	for (int i = 0; i < count; i++)
	{
		 printf("Film nr: %i \n ----------\n", i + 1);
		 printf("Nume:       %s \n", filme[i]->GetNume());
		 printf("An Lansare: %i \n", filme[i]->GetAnLansare());
		 printf("Scor IMBD:  %f \n", filme[i]->GetIMBD());
		 printf("Durata:     %i \n", filme[i]->GetDurata());
		 printf("\n");
	}
}

void MovieSeries::SortFilme()
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (filme[i]->GetAniTrecuti() < filme[j]->GetAniTrecuti())
				std::swap(filme[i], filme[j]);
		}
	}

	printf("\nFilmele au fost sortate in ordinea aparitiei\n");
}
