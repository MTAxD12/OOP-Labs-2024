#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <string>
Number::Number(const char* numar, int baza) {
	int countA = 0;
	for(int i = 0; numar[i] != '\0'; i++)
		countA++;

	this->count = countA;
	this->numarChar = new char[count + 1];
	this->baza = baza;

	for (int i = 0; i < count; i++)
		this->numarChar[i] = numar[i];
	this->numarChar[count] = '\0';
}

int countNr(int nr) {
	int countA = 0;
	while (nr)
	{
		nr /= 10;
		countA++;
	}
	return countA;
}

char* numToChar(int nr) {
	int countA = countNr(nr), i = 0;
	char* numar, *numarAux;
	numarAux = new char[countA + 1];
	numar = new char[countA + 1];
	while (nr)
	{
		numarAux[i++] = nr % 10 + '0';
		nr /= 10;
	}
	for (int i = countA - 1; i >= 0; i--)
	{
		numar[i] = numarAux[countA - 1 - i];
	}
	delete[] numarAux;
	numar[countA] = '\0';
	return numar;
}

Number::Number(int numar) {
	int countA = countNr(numar);
	char* numarAux;
	numarAux = new char[countA];
	numarAux = numToChar(numar);
	this->count = countA;
	this->numarChar = new char[count + 1];
	this->baza = 10;

	for (int i = count - 1; i >= 0; i--)
	{
		this->numarChar[i] = numarAux[count - 1 - i];
	}
	numarChar[count] = '\0';
	delete[] numarAux;
}

Number::Number(const Number& ex) {
	int countA = 0;
	for (int i = 0; ex.numarChar[i] != '\0'; i++)
		countA++;

	this->count = ex.count;
	this->numarChar = new char[count + 1];
	this->baza = ex.baza;

	for (int i = 0; i < count; i++)
		this->numarChar[i] = ex.numarChar[i];
	this->numarChar[count] = '\0';
}

Number::Number(const Number&& ex) noexcept {
	this->baza = ex.baza;
	this->count = ex.count;
	this->numarChar = new char[count + 1];

	for (int i = 0; i < count; i++)
		this->numarChar[i] = ex.numarChar[i];
	this->numarChar[count] = '\0';
	delete[] ex.numarChar;
}

Number::~Number() {
	delete[] numarChar;
}

Number Number::operator+(Number ex) {
    // Convert both numbers to base 10 for addition
    int num1 = std::stoi(this->numarChar, nullptr, this->baza);
    int num2 = std::stoi(ex.numarChar, nullptr, ex.baza);

    // Perform addition in base 10
    int result = num1 + num2;

    // Convert result back to the base of the larger base among the two numbers
    int newBase = std::max(this->baza, ex.baza);
	return *this;
}

Number Number::operator+(int numar) {
    // Convert numar to base 10 for addition
    int num1 = std::stoi(this->numarChar, nullptr, this->baza);

    // Perform addition in base 10
    int result = num1 + numar;

    // Convert result back to the base of the current number
	return *this;
}

Number Number::operator-(Number ex) {
    // Convert both numbers to base 10 for subtraction
    int num1 = std::stoi(this->numarChar, nullptr, this->baza);
    int num2 = std::stoi(ex.numarChar, nullptr, ex.baza);

    // Perform subtraction in base 10
    int result = num1 - num2;

    // Convert result back to the base of the larger base among the two numbers
    int newBase = std::max(this->baza, ex.baza);
	return *this;
}

void Number::operator++() {
    // Increment the number
    int num = std::stoi(this->numarChar, nullptr, this->baza) + 1;
    //*this = Number(num).SwitchBase(this->baza);
}

void Number::operator++(int numar) {
    // Increment the number
    int num = std::stoi(this->numarChar, nullptr, this->baza) + 1;
    //*this = Number(num).SwitchBase(this->baza);
}

void Number::operator--() {
    // Decrement the number
    int num = std::stoi(this->numarChar, nullptr, this->baza) - 1;
   //*this = Number(num).SwitchBase(this->baza);
}

void Number::operator--(int numar) {
    // Decrement the number
    int num = std::stoi(this->numarChar, nullptr, this->baza) - 1;
    //*this = Number(num).SwitchBase(this->baza);
}

bool Number::operator!() {
    // Check if the number is zero
    int num = std::stoi(this->numarChar, nullptr, this->baza);
    return num == 0;
}

int Number::operator[](int index) {
    // Return the digit at the given index
    if (index >= 0 && index < this->count)
        return this->numarChar[index] - '0';
    return -1;
}

Number& Number::operator=(Number&& ex) noexcept {
    // Move assignment operator
    if (this != &ex) {
        delete[] this->numarChar;
        this->numarChar = ex.numarChar;
        this->count = ex.count;
        this->baza = ex.baza;
        ex.numarChar = nullptr;
        ex.count = 0;
        ex.baza = 0;
    }
    return *this;
}

bool Number::operator<(Number ex) {
    
	int baza1 = this->baza, baza2 = ex.baza;
	SwitchBaseAux(*this, 10);
	SwitchBaseAux(ex, 10);

	if (this->count > ex.count) {
		return false;
	}
	else if (this->count < ex.count) {
		return true;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > ex.numarChar[i])
				return false;
			else if (this->numarChar[i] < ex.numarChar[i])
				return true;
		}
		return false; 
	}
	SwitchBaseAux(*this, baza1);
	SwitchBaseAux(ex, baza2);
}

bool Number::operator>(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	SwitchBaseAux(*this, 10);
	SwitchBaseAux(ex, 10);
    
	if (this -> count > ex.count) {
		return true;
	}
	else if (this -> count < ex.count) {
		return false;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > ex.numarChar[i])
				return true;
			else if (this->numarChar[i] < ex.numarChar[i])
				return false;
		}
		return false;
	}
	SwitchBaseAux(*this, baza1);
	SwitchBaseAux(ex, baza2);
}

bool Number::operator<=(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	SwitchBaseAux(*this, 10);
	SwitchBaseAux(ex, 10);

	if (this->count > ex.count) {
		return false;
	}
	else if (this->count < ex.count) {
		return true;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > ex.numarChar[i])
				return false;
			else if (this->numarChar[i] < ex.numarChar[i])
				return true;
		}
		return true;
	}
	SwitchBaseAux(*this, baza1);
	SwitchBaseAux(ex, baza2);
}

bool Number::operator>=(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	SwitchBaseAux(*this, 10);
	SwitchBaseAux(ex, 10);

	if (this->count > ex.count) {
		return true;
	}
	else if (this->count < ex.count) {
		return false;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > ex.numarChar[i])
				return true;
			else if (this->numarChar[i] < ex.numarChar[i])
				return false;
		}
		return true;
	}
	SwitchBaseAux(*this, baza1);
	SwitchBaseAux(ex, baza2);
}

bool Number::operator==(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	SwitchBaseAux(*this, 10);
	SwitchBaseAux(ex, 10);

	if (this->count == ex.count) {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] != ex.numarChar[i])
				return false;
		}
		return true;
	}
	else {
		return false;
	}
	SwitchBaseAux(*this, baza1);
	SwitchBaseAux(ex, baza2);
}

bool Number::operator<(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	SwitchBaseAux(*this, 10);
	char* numarAux; numarAux = new char[count2];
	numarAux = numToChar(numar);

	if (this->count > count2) {
		return false;
	}
	else if (this->count < count2) {
		return true;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > numarAux[i])
				return false;
			else if (this->numarChar[i] < numarAux[i])
				return true;
		}
		return false;
	}
	SwitchBaseAux(*this, baza1);
}

bool Number::operator>(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	SwitchBaseAux(*this, 10);
	char* numarAux; numarAux = new char[count2];
	numarAux = numToChar(numar);

	if (this->count > count2) {
		return true;
	}
	else if (this->count < count2) {
		return false;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > numarAux[i])
				return true;
			else if (this->numarChar[i] < numarAux[i])
				return false;
		}
		return false;
	}
	SwitchBaseAux(*this, baza1);
}

bool Number::operator<=(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	SwitchBaseAux(*this, 10);
	char* numarAux; numarAux = new char[count2];
	numarAux = numToChar(numar);

	if (this->count > count2) {
		return false;
	}
	else if (this->count < count2) {
		return true;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > numarAux[i])
				return false;
			else if (this->numarChar[i] < numarAux[i])
				return true;
		}
		return true;
	}
	SwitchBaseAux(*this, baza1);
}

bool Number::operator>=(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	SwitchBaseAux(*this, 10);
	char* numarAux; numarAux = new char[count2];
	numarAux = numToChar(numar);


	if (this->count > count2) {
		return true;
	}
	else if (this->count < count2) {
		return false;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] > numarAux[i])
				return true;
			else if (this->numarChar[i] < numarAux[i])
				return false;
		}
		return false;
	}
	SwitchBaseAux(*this, baza1);
}

bool Number::operator==(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	SwitchBaseAux(*this, 10);
	char* numarAux; numarAux = new char[count2];
	numarAux = numToChar(numar);

	if (this->count == count2) {
		for (int i = 0; i < count; i++)
		{
			if (this->numarChar[i] != numarAux[i])
				return false;
		}
		return true;
	}
	else {
		return false;
	}
	SwitchBaseAux(*this, baza1);
}

int operator-(Number ex, int numar) {
    // Subtract the integer from the number
    int num1 = std::stoi(ex.numarChar, nullptr, ex.baza);
    return num1 - numar;
}

void Number::SwitchBaseAux(Number &nmb, int newBase) {
	if (newBase < 2 || newBase > 16) {
		printf("Baza invalida\n");
		return;
	}

	long long int dec = 0;
	int power = 1;
	int lung = nmb.count;

	for (int i = lung - 1; i >= 0; --i) {
		int cifra;
		if (nmb.numarChar[i] >= '0' && nmb.numarChar[i] <= '9') {
			cifra = nmb.numarChar[i] - '0';
		}
		else if (nmb.numarChar[i] >= 'A' && nmb.numarChar[i] <= 'F') {
			cifra = nmb.numarChar[i] - 'A' + 10;
		}
		else {
			printf("Numarul dat nu contine doar cifre\n");
			return;
		}

		dec += cifra * power;
		power *= nmb.baza;
	}

	delete[] nmb.numarChar;

	int digits = 0;
	long long int temp = dec;
	while (temp > 0) {
		temp /= newBase;
		digits++;
	}

	nmb.numarChar = new char[digits + 1];
	nmb.numarChar[digits] = '\0';

	for (int i = digits - 1; i >= 0; --i) {
		nmb.numarChar[i] = "0123456789ABCDEF"[dec % newBase];
		dec /= newBase;
	}

	nmb.baza = newBase;
	nmb.count = digits;
}

void Number::SwitchBase(int newBase) {
	if (newBase < 2 || newBase > 16) {
		printf("Baza invalida\n");
		return;
	}

	long long int dec = 0;
	int power = 1;
	int lung = this->count;

	for (int i = lung - 1; i >= 0; --i) {
		int cifra;
		if (numarChar[i] >= '0' && numarChar[i] <= '9') {
			cifra = numarChar[i] - '0';
		}
		else if (numarChar[i] >= 'A' && numarChar[i] <= 'F') {
			cifra = numarChar[i] - 'A' + 10;
		}
		else {
			printf("Numarul dat nu contine doar cifre\n");
			return;
		}

		dec += cifra * power;
		power *= baza;
	}

	delete[] numarChar; 

	int digits = 0;
	long long int temp = dec;
	while (temp > 0) {
		temp /= newBase;
		digits++;
	}

	numarChar = new char[digits + 1];
	numarChar[digits] = '\0';

	for (int i = digits - 1; i >= 0; --i) {
		numarChar[i] = "0123456789ABCDEF"[dec % newBase];
		dec /= newBase;
	}

	baza = newBase; 
	count = digits;
}

void Number::Print() {
	printf("Numarul este: %s, nr de cifre este: %d iar baza este: %d\n", 
		this->numarChar, this->GetDigitsCount(), this->GetBase());
}

int Number::GetDigitsCount() {
	return this->count;
}

int Number::GetBase() {
	return baza;
}