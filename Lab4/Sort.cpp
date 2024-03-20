#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib> 
#include <algorithm>
#include <cstdarg>
#include <initializer_list>

Sort::Sort(int nr, int min, int max)
{
	this->marime = nr;
	elemente = new int[marime];

	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < marime; i++)
		elemente[i] = min + rand() % (max - min + 1);
}

Sort::Sort(std::initializer_list<int> list) : marime((int)list.size())
{
	elemente = new int[marime];
	std::copy(list.begin(), list.end(), elemente);
}

Sort::Sort(int count, int *elemAux)
{
	this->marime = count;
	elemente = new int[marime];

	for (int i = 0; i < marime; i++)
	{
		elemente[i] = elemAux[i];
	}
}

Sort::Sort(int count, ...)
{
	this->marime = count;
	elemente = new int[marime];

	va_list param;
	va_start(param, count);

	for (int i = 0; i < count; i++)
		elemente[i] = va_arg(param, int);

	va_end(param);
}

Sort::Sort(char* numere)
{
	int elemAux[256], lgNr = 0, nr = 0;
	char nrChar[100];
	
	for (int i = 0; i <= strlen(numere); i++)
	{
		if (numere[i] == ',' || numere[i] == '\0')
		{
			int cif = 0;

			for(int j = i - lgNr; j < i; j++)
				nrChar[cif++] = numere[j];

			elemAux[nr++] = charToInt(nrChar);
			lgNr = 0;
		}
		else
			lgNr++;
	}


	this->marime = nr;
	elemente = new int[marime];

	for (int i = 0; i < nr; i++)
		elemente[i] = elemAux[i];
}

int Sort::charToInt(char* nr)
{
	int numar = 0;
	for (int i = 0; nr[i]; i++)
		if (nr[i] >= '0' && nr[i] <= '9')
			numar = numar * 10 + (nr[i] - '0'), nr[i] = ' ';


	//printf("nr: %d \n", numar);
	return numar;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < marime; i++)
	{
		int cheie = elemente[i];
		int j = i - 1;
		while (j >= 0 && elemente[j] < cheie)
		{
			elemente[j + 1] = elemente[j];
			j = j - 1;
		}
		elemente[j + 1] = cheie;
	}
	if (ascendent)
		for (int i = 0; i < marime/2; i++)
			std::swap(elemente[i], elemente[marime - i - 1]);

}

int Sort::partition(int min, int max)
{
	int pivot = elemente[max];
	int i = (min - 1);

	for (int j = min; j <= max; j++)
	{
		if (elemente[j] > pivot)
		{
			i++;
			std::swap(elemente[i], elemente[j]);
		}
	}
	std::swap(elemente[i + 1], elemente[max]);
	return (i + 1);
}

void Sort::quickSort(int min, int max, bool ascendent)
{
	if (min < max)
	{
		int pi = partition(min, max);
		quickSort(min, pi - 1, ascendent);
		quickSort(pi + 1, max, ascendent);
	}
}


void Sort::QuickSort(bool ascendent)
{
	quickSort(0, marime - 1, ascendent);

	if (ascendent)
		for (int i = 0; i < marime / 2; i++)
			std::swap(elemente[i], elemente[marime - i - 1]);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < marime - 1; i++)
		for (int j = i + 1; j < marime; j++)
			if (elemente[i] < elemente[j])
				std::swap(elemente[i], elemente[j]);
	if (ascendent)
		for (int i = 0; i < marime / 2; i++)
			std::swap(elemente[i], elemente[marime - i - 1]);
}

void Sort::Print()
{
	for (int i = 0; i < marime; i++)
		printf("%d ", elemente[i]);

	printf("\n");
}

int Sort::GetElementsCount()
{
	return marime;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < marime)
		return elemente[index];

	printf("Elementul nu se afla in vector\n");
	return -1;
}

