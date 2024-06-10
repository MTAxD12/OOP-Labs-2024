#include "Hexazecimal.h"

string Hexazecimal::GetFormatName()
{
    return "Hexazecimal";
}

string Hexazecimal::FormatNumber(int number)
{
    char buffer[50];
    sprintf_s(buffer, "0x%08X", number);
    return string(buffer);
}
