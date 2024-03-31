#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>

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

Number::Number(int numar) {
	printf("Constructorul cu un singur parametru!\n");
}

Number::Number(const Number& ex) {
	printf("Copy constructor\n");
}

Number::Number(const Number&& ex) {
	printf("Move constructor\n");
}

Number::~Number() {
}

Number Number::operator+(Number ex) {
	printf("Operatorul + apelat in format operator+(Number ex)\n");
	return Number("test", 3);
}

Number Number::operator+(int numar) {
	printf("Operatorul + apelat in format operator+(int numar)\n");
	return Number("test", 3);
}

Number Number::operator-(Number ex) {
	printf("Operatorul - apelat in format operator-(Number ex)\n");
	return Number("test", 3);
}

void Number::operator++() {
	printf("Operatorul ++ apelat in format prefixat\n");
}

void Number::operator++(int numar) {
	printf("Operatorul ++ apelat in format postfixat\n");
}

void Number::operator--() {
	printf("Operatorul -- apelat in format prefixat\n");
}

void Number::operator--(int numar) {
	printf("Operatorul -- apelat in format postfixat\n");
}

bool Number::operator!() {
	printf("Operatorul !\n");
	return false;
}

int Number::operator[](int index) {
	printf("Operatorul de indexare\n");
	return index;
}

Number& Number::operator=(Number&& ex) noexcept {
	printf("Move assignment operator\n");
	return *this;
}

bool Number::operator<(Number ex) {
	printf("Operatorul < cu parametru Number\n");
	return true;
}

bool Number::operator>(Number ex) {
	printf("Operatorul > cu parametru Number\n");
	return true;
}

bool Number::operator<=(Number ex) {
	printf("Operatorul <= cu parametru Number\n");
	return true;
}

bool Number::operator>=(Number ex) {
	printf("Operatorul >= cu parametru Number\n");
	return true;
}

bool Number::operator==(Number ex) {
	printf("Operatorul == cu parametru Number\n");
	return true;
}

bool Number::operator<(int numar) {
	printf("Operatorul < cu parametru int\n");
	return true;
}

bool Number::operator>(int numar) {
	printf("Operatorul > cu parametru int\n");
	return true;
}

bool Number::operator<=(int numar) {
	printf("Operatorul <= cu parametru int\n");
	return true;
}

bool Number::operator>=(int numar) {
	printf("Operatorul >= cu parametru int\n");
	return true;
}

bool Number::operator==(int numar) {
	printf("Operatorul == cu parametru int\n");
	return true;
}

int operator-(Number ex, int numar) {
	printf("Sunt in functia operator- care va fi utilizata ca si friend\n");
	return 0;
}

void Number::SwitchBase(int newBase) {
	if (newBase < 2 || newBase > 16) {
		printf("Baza invalida\n");
		return;
	}

	long long int dec = 0;
	int power = 1;
	int lung = strlen(numarChar);

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