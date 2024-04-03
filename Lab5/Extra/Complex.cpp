#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex operator+ (const Complex& n1, const Complex& n2) {
    return Complex(n1.real() + n2.real(), n1.imag() + n2.imag());
}
Complex operator+(const Complex& n1, double n2) {
    return Complex(n1.real() + n2, n1.imag());
}
Complex operator+(double n1, const Complex& n2) {
    return Complex(n1 + n2.real(), n2.imag());
}

Complex operator-(const Complex& nr) {
    return Complex(-nr.real(), -nr.imag());
}
Complex operator-(double n1, const Complex& n2) {
    return Complex(n1 - n2.real(), n2.imag());
}
Complex operator-(const Complex& n1, double n2) {
    return Complex(n1.real() - n2, n1.imag());
}
Complex operator-(const Complex& n1, const Complex& n2) {
    return Complex(n1.real() - n2.real(), n1.imag() - n2.imag());
}

Complex operator*(const Complex& n1, const Complex& n2) {
    return Complex((n1.real() * n2.real() - n1.imag() * n2.imag()), (n1.real() * n2.imag() + n2.real() * n1.imag()));
}
Complex operator*(const Complex& n1, double n2) {   
    return Complex(n1.real() * n2, n1.imag() * n2);
}
Complex operator*(double n1, const Complex& n2) {
    return Complex(n2.real() * n1, n2.imag() * n1);
}


bool operator==(const Complex& n1, const Complex& n2) {
    if (n1.real() == n2.real() && n1.imag() == n2.imag())
        return true;
    else 
        return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& nr) {
    if (nr.real() != 0 && nr.imag() != 0)
        out << nr.real() << " + " << nr.imag() << "i";
    else if (nr.real() == 0 && nr.imag() != 0)
        out << nr.imag() << "i";
    else if (nr.real() != 0 && nr.imag() == 0)
        out << nr.real();
    else
        out << 0;
    return out;
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

bool operator!=(const Complex& n1, const Complex& n2) {
    if ((n1.real() != n2.real()) || (n1.imag() != n2.imag()))
        return true;
    else
        return false;
}

Complex& Complex::operator++() {
    this->real_data++;
    return *this;
}

Complex Complex::operator++(int arg) {
    Complex aux = *this;
    this->real_data++;
    return aux;
}

Complex& Complex::operator--() {
    this->real_data--;
    return *this;
}

Complex Complex::operator--(int arg) {
    Complex aux = *this;
    this->real_data--;
    return aux;
}