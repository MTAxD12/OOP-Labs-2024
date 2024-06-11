#include "Suma.h"

Suma::Suma()
{
}

void Suma::Run(int* a, int count)
{
    int s = 0;
    for (int i = 0; i < count; i++)
        s += a[i];

    cout << "Suma = " << s << "\n";

}
