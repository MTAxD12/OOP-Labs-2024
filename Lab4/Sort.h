#pragma once
#include <initializer_list>

class Sort
{
    int* elemente;
    int marime;
    int partition(int min, int max);
    void quickSort(int min, int max, bool ascendent);
    int charToInt(char* nr);
public:
    Sort(int nr, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(int count, int *elemAux);
    Sort(int count, ...);
    Sort(char* numere);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

