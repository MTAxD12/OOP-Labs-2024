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
	char *numarAux;
	numarAux = new char[countA + 1];
	while (nr)
	{
		numarAux[i++] = nr % 10 + '0';
		nr /= 10;
	}
	numarAux[countA] = '\0';
	return numarAux;
}

long long int charToInt(char* numar) {
	int count = strlen(numar), numarInt = 0;
	for (int i = count - 1; i >= 0; i--) {
		numarInt = (numarInt * 10) + numar[i] - '0';
	}

	return numarInt;
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
	int lgMax = 0, bazaMax, baza1 = this->baza, baza2 = ex.baza;

	if (this->baza >= ex.baza) bazaMax = this->baza, ex.SwitchBase(bazaMax);
	else bazaMax = ex.baza, this->SwitchBase(bazaMax);

	if (this->count >= ex.count) lgMax = this->count;
	else lgMax = ex.count; lgMax++;

	char* rezultat = new char[lgMax + 1];
	for (int i = 0; i < lgMax; i++)
		rezultat[i] = '0';

	int carry = 0, index = lgMax - 1;

	for (int i = this->count, j = ex.count; i >= 0 || j >= 0 || carry; --i, --j, --index) {
		int cifra1, cifra2;
		if (i >= 0) cifra1 = this->numarChar[i] - '0';
		else cifra1 = 0;
		if (j >= 0) cifra2 = ex.numarChar[j] - '0';
		else cifra2 = 0;

		int suma = cifra1 + cifra2 + carry;
		carry = suma / 10;
		rezultat[index] = (suma % 10) + '0';
	}
	

	if (rezultat[0] == '0') 
		for (int i = 0; i < lgMax; i++)
			this->numarChar[i] = rezultat[i + 1];
	else
		for (int i = 0; i < lgMax; i++)
			this->numarChar[i] = rezultat[i];

	delete[] rezultat;

	if (baza1 > baza2)
		ex.SwitchBase(baza2);

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
	if (this->numarChar[this->count - 1] < (this->baza <= 10 ? '9' : 'F')) {
		++this->numarChar[this->count - 1];
	}
	else {
		int index = this->count - 1;
		while (index >= 0 && (this->numarChar[index] == '9' || this->numarChar[index] == 'F')) {
			this->numarChar[index] = '0';
			--index;
		}
		if (index < 0) {
			char* newNumarChar = new char[this->count + 2];
			newNumarChar[0] = (this->baza <= 10) ? '1' : 'A';
			std::fill_n(newNumarChar + 1, this->count + 1, '0');
			std::copy(this->numarChar, this->numarChar + this->count, newNumarChar + 1);
			delete[] this->numarChar;
			this->numarChar = newNumarChar;
			++this->count;
		}
		else {
			++this->numarChar[index];
		}
	}
}

void Number::operator++(int numar) {
	Number temp(*this);
	++(*this);
}

void Number::operator--() {
	for (int i = 0; i < count - 1; i++)
		this->numarChar[i] = this->numarChar[i + 1];
	this->numarChar[count-1] = '\0';
	--this->count;
}

void Number::operator--(int numar) {
	if (this->count)
		this->numarChar[this->count - 1] = '\0';
	this->count = this->count - 1;
}

int Number::operator[](int index) {
	return this->numarChar[index];	
}

Number& Number::operator=(Number&& ex) noexcept {
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
	this->SwitchBase(10);
	ex.SwitchBase(10);

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
	this->SwitchBase(baza1);
	ex.SwitchBase(baza2);
}

bool Number::operator>(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	this->SwitchBase(10);
	ex.SwitchBase(10);
    
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
	this->SwitchBase(baza1);
	ex.SwitchBase(baza2);
}

bool Number::operator<=(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	this->SwitchBase(10);
	ex.SwitchBase(10);

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
	this->SwitchBase(baza1);
	ex.SwitchBase(baza2);
}

bool Number::operator>=(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	this->SwitchBase(10);
	ex.SwitchBase(10);

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
	this->SwitchBase(baza1);
	ex.SwitchBase(baza2);
}

bool Number::operator==(Number ex) {
	int baza1 = this->baza, baza2 = ex.baza;
	this->SwitchBase(10);
	ex.SwitchBase(10);

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
	this->SwitchBase(baza1);
	ex.SwitchBase(baza2);
}

bool Number::operator<(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	this->SwitchBase(10);
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
	this->SwitchBase(baza1);
}

bool Number::operator>(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	this->SwitchBase(10);
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
	this->SwitchBase(baza1);
}

bool Number::operator<=(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	this->SwitchBase(10);
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
	this->SwitchBase(baza1);
}

bool Number::operator>=(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	this->SwitchBase(10);
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
	this->SwitchBase(baza1);
}

bool Number::operator==(int numar) {
	int baza1 = this->baza, count2 = countNr(numar);
	this->SwitchBase(10);
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
	this->SwitchBase(baza1);
}

int operator-(Number ex, int numar) {
	int bazaInit = ex.baza;
	ex.SwitchBase(10);

	int countA = countNr(numar);
	char* numarAux = new char[countA + 1];
	numarAux = numToChar(numar);

	int lgMax;
	if (ex.count > countA) lgMax = ex.count;
	else lgMax = countA;

	char* rezultat = new char[lgMax + 1];

	for (int i = 0; i < lgMax; i++)
		rezultat[i] = '0';
	rezultat[lgMax] = '\0';

	int carry = 0;
	for (int i = 0; i < lgMax; ++i) {
		int cifra1, cifra2;
		if (i < ex.count)
			cifra1 = (ex.numarChar[ex.count - 1 - i] - '0');
		else 
			cifra1 = 0;

		if (i < countA)
			cifra2 = (numarAux[countA - 1 - i] - '0');
		else
			cifra2 = 0;

		int dif = cifra1 - cifra2 - carry;
		if (dif < 0) {
			dif += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}

		rezultat[lgMax - 1 - i] = dif + '0';
	}

	int zerouri = 0;
	while (zerouri < lgMax && rezultat[zerouri] == '0') {
		++zerouri;
	}

	if (zerouri > 0) {
		memmove(rezultat, rezultat + zerouri, lgMax - zerouri + 1);
	}
	
	ex.SwitchBase(bazaInit);
	return charToInt(rezultat);
}

/*void Number::SwitchBaseAux(Number& nmb, int newBase) {
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
			printf("Numarul dat nu contine doar cifre\n")
			cifra  ;
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
*/

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
