#pragma once
#include <iostream>
using namespace std;
class complex {
	
	double real; 
	double imaginary; 

public:
    
	complex();
	complex(double r, double i); 
	complex(double r);
	complex(const complex& other);
	~complex();
	complex operator+(const complex& other);
	complex operator-(const complex& other);
	complex operator*(const complex& other);
	complex operator/(const complex& other);
	void operator+=(const complex& other);
	void operator-=(const complex& other);
	complex& operator++();
	complex& operator--();
	complex operator++(int value);
	complex operator--(int value);
	complex operator^(int d);
	bool operator ==(const complex& other);
	bool operator !=(const complex& other);

	//_____________________________________________________________
	friend ostream& operator << (ostream& os,  const complex& com);
	friend istream& operator >> (istream& in, complex& com);

};


