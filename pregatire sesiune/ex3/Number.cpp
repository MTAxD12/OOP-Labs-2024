#include "Number.h"
#include <iostream>

Number::Number(int value) : printers{ nullptr }
{
    this->number = value;
    this->count = 1;
}

Number::operator int()
{
    return (int)this->number;
}

Number Number::operator+(Number n)
{
    return Number(this->number + n.number);
}

Number Number::operator-(Number n)
{
    return Number(this->number - n.number);
}

Number Number::operator*(Number n)
{
    return Number(this->number * n.number);
}

Number Number::operator/(Number n)
{
    return Number(this->number / n.number);
}

Number& Number::operator+=(Printer* prnt)
{
    this->printers.push_back(prnt);
    this->count++;
    return *this;
}

void Number::Print()
{
    for (int i = 0; i < count; i++)
    {
        if (this->printers[i] != nullptr)
        {
            std::cout << "Format: " << this->printers[i]->GetFormatName() << " Value: " << this->printers[i]->FormatNumber(this->number) << std::endl;
        }
    }
}
