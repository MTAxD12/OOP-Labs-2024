#pragma once
class Number
{
	char* numarChar;
	int baza;
	int count;

public:
	Number();
	Number(const char* numar, int baza); //default constructor
	Number(int ex);
	Number(const Number& ex); //copy constructor
	Number(const Number&& ex); //move constructor
	~Number();

	//cum suprascriu un operator?
	//<tip_de_return> operator<operator> (<parametri>)
	//tip de return in functie de ceea ce ne dorim noi sa returneze

	Number operator+(Number ex);//adition
	Number operator+(int numar); //adition
	Number operator-(Number ex); //substract
	friend int operator-(Number ex, int numar); //substract


	void operator++(); //pentru ++Number
	void operator++(int numar); //pentru Number++
	void operator--(); //pentru --Number
	void operator--(int numar); //pentru Number--


	bool operator!();
	int operator[](int index); //index operator

	Number& operator=(Number&& ex) noexcept; //move asignment operator

	bool operator<(Number ex);
	bool operator>(Number ex);
	bool operator<=(Number ex);
	bool operator>=(Number ex);
	bool operator==(Number ex);
	bool operator<(int numar);
	bool operator>(int numar);
	bool operator<=(int numar);
	bool operator>=(int numar);
	bool operator==(int numar);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
};