#pragma once
#include <iostream>
#include <vector>
#include "Procesator.h"
#include <vector>
#include <initializer_list>

using namespace std;

class MyVector
{
private:
	vector<int> Data;
	vector<Procesator*> processors;
public:
	MyVector();
	void process();
	void clear();
	MyVector& operator+=(int el);
	MyVector& operator+=(initializer_list<int> list);
	MyVector& operator+=(Procesator* p);
	operator int();
	operator unsigned int();
};

