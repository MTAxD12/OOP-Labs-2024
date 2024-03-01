#include <stdio.h>
#include <iostream>

struct cuvinte 
{
    char cuvant[200];
    int nrCif;
}cuv[100];

bool cuvMaiMare(char a[], char b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return 0;
    }

    return 1;
}

int main()
{
    char propozitie[200];

    if (scanf_s("%200[^\n]", propozitie, sizeof(propozitie)) != 1) {
        printf("Eroare\n");
        return 1;
    }

    //printf("%s", propozitie);

    int lgCuv = 0, nrCuv = 1;
    for (int i = 0; i <= sizeof(propozitie); i++)
    {
        if (propozitie[i] == ' ' || propozitie[i] == '\0')
        {
            int litera = 0;
            for (int j = i - lgCuv; j <= i - 1; j++)
            {
                cuv[nrCuv].cuvant[litera++] = propozitie[j];
            }

            cuv[nrCuv].nrCif = lgCuv;
            nrCuv++;
            lgCuv = 0;
        }
        else
            lgCuv++;
    }

    for (int i = 1; i <= nrCuv; i++)
    {
        for (int j = i + 1; j < nrCuv; j++)
        {
            if (cuv[i].nrCif <= cuv[j].nrCif)
            {
                std::swap(cuv[i], cuv[j]);
            }
        }
    }

    for (int i = 1; i <= nrCuv; i++)
    {
        for (int j = i + 1; j < nrCuv; j++)
        {
            if (cuv[i].nrCif == cuv[j].nrCif)
            {
                if(!cuvMaiMare(cuv[i].cuvant, cuv[j].cuvant, cuv[i].nrCif))
                    std::swap(cuv[i], cuv[j]);
            }
        }
    }

    for (int i = 1; i < nrCuv; i++)
    {
        printf("%s\n", cuv[i].cuvant);
    }
}