#include "MyVector.h"

MyVector::MyVector()
{
}

void MyVector::process()
{
	for (int i = 0; i < processors.size(); i++)
	{
		processors[i]->Run(this->Data.data(), this->Data.size());
	}
}

void MyVector::clear()
{
	Data.clear();
}

MyVector& MyVector::operator+=(int el)
{
	Data.push_back(el);
	return *this;
}

MyVector& MyVector::operator+=(std::initializer_list<int> list)
{
	for (int elem : list) {
		Data.push_back(elem);
	}
	return *this;
}
MyVector& MyVector::operator+=(Procesator* p)
{
	processors.push_back(p);
	return *this;
}

MyVector::operator int()
{
	return (int)Data.size();
}

MyVector::operator unsigned int()
{
	return (unsigned int)processors.size();
}
