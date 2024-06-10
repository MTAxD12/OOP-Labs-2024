#pragma once
#include "Printer.h"
#include <iostream>
#include <vector>
class Number
{
private:
    int number;
    vector<Printer*> printers; 
    int count;

public:
    Number(int value);
    operator int();
    Number operator+(Number n);
    Number operator-(Number n);
    Number operator*(Number n);
    Number operator/(Number n);
    Number& operator+=(Printer* prnt);
    void Print();
};