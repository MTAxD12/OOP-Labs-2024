#pragma once
#include "Article.h"
#include <iostream>

using namespace std;

class Book : public Article
{
private:
	string title;
	string author;
	int price;
	int quantity;
public:
	Book(int price, int quantity, string title, string author);
	string GetAuthor();
	string GetTitle();
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
};

