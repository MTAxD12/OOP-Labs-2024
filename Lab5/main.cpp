#include "Number.h"
#include <iostream>
Number Get(Number ex) { return ex; }

int main()
{
    Number n1("344", 10);
    n1.Print();
    n1.SwitchBase(8);
    n1.Print();
   
    Number n2(344);
    n2.Print();
    n2.SwitchBase(8);
    n2.Print();

    if (n1 <= 344)
        printf("da\n");
    else
        printf("nu\n");

    n1.Print();
    n2.Print();
}