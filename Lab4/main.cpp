#include "Sort.h"
#include <iostream>

int main()
{
	Sort sort1(10, 23, 99);
	sort1.InsertSort();
	sort1.BubbleSort();
	sort1.QuickSort(true);
	sort1.Print();

	Sort sort2({1, 2, 3, 4, 5, 6, 7, 8});
	sort2.InsertSort();
	sort2.Print();

	int num[] = {3, 1, 35, 434, 43, 2};
	Sort sort3(6, num);
	sort3.BubbleSort(true);
	sort3.Print();

	Sort sort4(5, 12, 34, 2, 35, 399);
	sort4.InsertSort();
	sort4.Print();

	char sort5C[] = "34,223,45,2,67,64,28,123,123,0,323,9830";
	Sort sort5(sort5C);
	sort5.QuickSort(true);
	sort5.Print();
}