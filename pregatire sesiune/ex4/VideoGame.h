#pragma once
#include "Article.h"
#include <iostream>

using namespace std;

class VideoGame : public Article
{
private:
	string platform;
	string name;
	int price;
	int quantity;
public:
	VideoGame(int price, int quantity, string platform, string name);
	string GetPlatform();
	string GetName();
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
};

