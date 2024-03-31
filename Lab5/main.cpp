#include "Number.h"
#include <iostream>
Number Get(Number ex) { return ex; }

int main()
{
    Number n1("101011111111111111001", 2);
    n1.Print();
    n1.SwitchBase(10);
    n1.Print();
    n1.SwitchBase(16);
    n1.Print();
    n1.SwitchBase(4);
    n1.Print();
    n1.SwitchBase(2);
    n1.Print();
}