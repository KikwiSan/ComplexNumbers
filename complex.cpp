#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;
complex::complex() {
	real = imaginary = 0;
};

complex::complex(double r, double i)
{
	real = r;
	imaginary = i;
}

complex::complex(double r)
{
	this->real = r;
	this->imaginary = 0;
}

complex::complex(const complex& other) {
	this->real = other.real;
	this->imaginary = other.imaginary;
}

complex::~complex() {};

complex complex::operator+(const complex& other) {
	complex res;
	res.real = this->real + other.real;
	res.imaginary = this->imaginary + other.imaginary;
	return res;
}

complex complex::operator-(const complex& other) {
	complex res;
	res.real = this->real - other.real;
	res.imaginary = this->imaginary - other.imaginary;
	return res;
}

complex complex::operator*(const complex& other)
{
	complex res;
	res.real = this->real * other.real - this->imaginary * other.imaginary;
	res.imaginary = this->real * other.imaginary + this->imaginary * other.real;
	return res;
}

complex complex::operator/(const complex& other)
{
	complex res;
	res.real = (this->real * other.real - this->imaginary * other.imaginary) /
		(other.real * other.real + other.imaginary * other.imaginary);
	res.imaginary = (this->imaginary * other.real - this->real * other.imaginary) /
		(other.real * other.real + other.imaginary * other.imaginary);
	return res;
}

void complex::operator+=(const complex& other) 
{
	this->real += other.real;
	this->imaginary += other.imaginary;
}

void complex::operator-=(const complex& other)
{
	this->real -= other.real;
	this->imaginary -= other.imaginary;
}

complex complex::operator++(int value) {
	complex rez(this->real,this->imaginary);
	this->imaginary++;
	this->real++;
	return rez;
}

complex& complex::operator++() {
	this->imaginary++;
	this->real++;
	return *this;
}

complex complex::operator--(int value) {
	complex rez(this->real, this->imaginary);
	this->imaginary--;
	this->real--;
	return rez;
}

complex& complex::operator--() {
	this->imaginary--;
	this->real--;
	return *this;
}

complex complex::operator^(int d) {
	complex rez;
	double pi = 3.14159;
	double a = this->real;
	double b = this->imaginary;
	double p = sqrt(a*a+b*b);
	short part;
	if (a > 0 && b > 0) part = 1;
	else if (a < 0 && b>0) part = 2;
	else if (a < 0 && b < 0) part = 3;
	else  part = 4;
	double fi = acos(a / p);
	if (part == 1 || part == 2) { }
	else fi = -fi;
	rez.real = pow(p, d) * (cos(d * fi));
	rez.imaginary = pow(p, d) * (sin(d * fi));
	return rez;
}

bool complex::operator ==(const complex& other) {
	double a = (this->real - other.real) + (this->imaginary - other.imaginary);
	return !a;
}

bool complex::operator !=(const complex& other) {
	double a = (this->real - other.real) + (this->imaginary - other.imaginary);
	return a;
}

//______________________________________________________
ostream& operator << (ostream& out, const complex& other) {
	if (other.imaginary >= 0)
		out << other.real << " + " << other.imaginary << "i";

	else
		out << other.real << " - " << -other.imaginary << "i";
	return out;
}

istream& operator >> (istream& in, complex& other) {
	cout << "enter Rez:";
	cin >> other.real;
	cout << "enter Img:";
	cin >> other.imaginary;
	return in;
}