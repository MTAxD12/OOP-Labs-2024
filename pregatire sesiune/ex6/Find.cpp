#include "Find.h"

Find::Find(function<bool(int)> fnc)
{
	this->fnc = fnc;
}

void Find::Run(int* a, int count)
{
	int cnt = 0;
	for (int i = 0; i < count; i++)
		if (this->fnc(a[i]))
			cnt++;

	cout << "Find = " << cnt << " elemnts\n";
}
