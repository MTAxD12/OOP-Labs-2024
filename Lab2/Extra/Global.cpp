#include "Global.h"
#include <string.h>

int compare_nume(Movie* f1, Movie* f2) {
	if (strcmp(f1->GetNume(), f2->GetNume()) < 0)
		return -1;
	else if (strcmp(f1->GetNume(), f2->GetNume()) == 0)
		return 0;
	else
		return 1;
}

int compare_an_lan(Movie* f1, Movie* f2) {
	if (f1->GetAnLansare() < f2->GetAnLansare())
		return -1;
	else if (f1->GetAnLansare() == f2->GetAnLansare())
		return 0;
	else
		return 1;
}

int compare_scor(Movie* f1, Movie* f2) {
	if (f1->GetIMBD() < f2->GetIMBD())
		return -1;
	else if (f1->GetIMBD() == f2->GetIMBD())
		return 0;
	else
		return 1;
}

int compare_durata(Movie* f1, Movie* f2) {
	if (f1->GetDurata() < f2->GetDurata())
		return -1;
	else if (f1->GetDurata() == f2->GetDurata())
		return 0;
	else
		return 1;
}

int compare_ani_trc(Movie* f1, Movie* f2) {
	if (f1->GetAniTrecuti() < f2->GetAniTrecuti())
		return -1;
	else if (f1->GetAniTrecuti() == f2->GetAniTrecuti())
		return 0;
	else
		return 1;
}
