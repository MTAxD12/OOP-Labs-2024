#include "Apple.h"

Apple::Apple(int price, int quantity, string origine)
{
	this->price = price;
	this->quantity = quantity;
	this->origine = origine;
}

string Apple::GetOrigine()
{
	return origine;
}

string Apple::GetType()
{
	return "Apple";
}

int Apple::GetQuantity()
{
	return quantity;
}

int Apple::GetPrice()
{
	return price;
}

void Apple::Print()
{
	cout << GetType() << " (from=" << GetOrigine() << ") Price="
		<< GetPrice() << " Quantity=" << GetQuantity() << "\n";
}
