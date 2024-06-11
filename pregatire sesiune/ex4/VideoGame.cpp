#include "VideoGame.h"

VideoGame::VideoGame(int price, int quantity, string platform, string name)
{
	this->price = price;
	this->quantity = quantity;
	this->platform = platform;
	this->name = name;
}

string VideoGame::GetPlatform()
{
	return this->platform;
}

string VideoGame::GetName()
{
	return this->name;
}

string VideoGame::GetType()
{
	return "VideoGame";
}

int VideoGame::GetQuantity()
{
	return quantity;
}

int VideoGame::GetPrice()
{
	return price;
}

void VideoGame::Print()
{
	cout << GetType() << " (Platform=" << GetPlatform() << ", Name=" << GetName() << ") Price="
		<< GetPrice() << " Quantity=" << GetQuantity() << "\n";
}
