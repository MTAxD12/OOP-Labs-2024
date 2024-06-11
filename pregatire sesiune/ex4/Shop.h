#pragma once
#include "Article.h"
#include <iostream>
#include <vector>

using namespace std;

class Shop
{
private:
	vector<Article*> items;
public:
	Shop& Add(Article* a);
	int GetTotalPrice();
	int GetQuantity(string type);
	void List();
};

