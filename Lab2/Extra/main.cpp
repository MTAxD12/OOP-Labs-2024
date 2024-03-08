#include "Movie.h"
#include "MovieSeries.h"
#include "Global.h"

#include <iostream>

using namespace std;

int main()
{
	Movie *film1, *film2;
	film1 = new Movie; film2 = new Movie;
	char numeF1[256], numeF2[256];

	strcpy_s(numeF1, "American Psycho");
	film1->SetareNume(numeF1);
	film1->SetareAnLansare(2000);
	film1->SetareDurata(104);
	film1->SetareIMBD(7.6f);

	strcpy_s(numeF2, "Scarface");
	film2->SetareNume(numeF2);
	film2->SetareAnLansare(1983);
	film2->SetareDurata(170);
	film2->SetareIMBD(8.3f);


	printf(
		R"(
%s | %s comparatie:
nume       : %d
an lansare : %d
scor       : %d
durata     : %d
ani trecuti: %d
)",
film1->GetNume(),
film2->GetNume(),
compare_nume(film1, film2),
compare_an_lan(film1, film2),
compare_scor(film1, film2),
compare_durata(film1, film2),
compare_ani_trc(film1, film2));

	MovieSeries smecheri;
	smecheri.Init();
	smecheri.AddFilm(film1);
	smecheri.AddFilm(film2);
	smecheri.PrintFilme();
	smecheri.SortFilme();
	smecheri.PrintFilme();
}