#pragma once
#include "Printer.h"
#include <string>
class Hexazecimal : public Printer
{
public:
	string GetFormatName() override;
	string FormatNumber(int number) override;
};

