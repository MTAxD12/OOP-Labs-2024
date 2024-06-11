#include "Book.h"

Book::Book(int price, int quantity, string title, string author)
{
	this->title = title;
	this->author = author;
	this->price = price;
	this->quantity = quantity;
}

string Book::GetType()
{
	return "Book";
}

string Book::GetAuthor()
{
	return author;
}

string Book::GetTitle()
{
	return title;
}

int Book::GetQuantity()
{
	return quantity;
}

int Book::GetPrice()
{
	return price;
}

void Book::Print()
{
	cout << GetType() << " (Title=" << GetTitle() << ", Author=" << GetAuthor() << ") Price="
		<< GetPrice() << " Quantity=" << GetQuantity() << "\n";
}
