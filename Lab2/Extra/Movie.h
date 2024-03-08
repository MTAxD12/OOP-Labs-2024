#pragma once

class Movie
{
	char numeFilm[256];
	int anLansare;
	float imbd;
	int durata;
public:
	Movie();

	void SetareNume(char* nume);
	char* GetNume();

	void SetareAnLansare(int an);
	int GetAnLansare();

	void SetareIMBD(float scor);
	float GetIMBD();

	void SetareDurata(int minute);
	int GetDurata();

	int GetAniTrecuti();
};


