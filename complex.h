#pragma once
#include <iostream>
using namespace std;
class complex {
	
	double real; //действительная часть
	double imaginary; //мнимая часть

public:
    
	complex();//конструкторы
	complex(double r, double i); 
	complex(double r);
	complex(const complex& other);//конструктор копирования
	~complex();//деструктор
	complex operator+(const complex& other); //сложение
	complex operator-(const complex& other);//вычитание
	complex operator*(const complex& other);//умножение
	complex operator/(const complex& other);//деление
	void operator+=(const complex& other);//оператор +=
	void operator-=(const complex& other);//оператор -=
	complex& operator++();//префиксный инкремент
	complex& operator--();//префиксный дикремент
	complex operator++(int value);//постфиксный инкремент
	complex operator--(int value);//постфиксный дикремент
	complex operator^(int d);//оператор возведения в степень
	bool operator ==(const complex& other);//операторы проверок равенства
	bool operator !=(const complex& other);

	//перегрузка ввода вывода________________________________________
	friend ostream& operator << (ostream& os,  const complex& com);
	friend istream& operator >> (istream& in, complex& com);

};


