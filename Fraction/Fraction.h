#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4326)
#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
class Fraction
{
	int integer; //выделение целой части
	int numerator; //числитель 
	int denominator; //знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	Fraction();
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//                                 OPERATORS
	//по принципу методов, при целой части
	Fraction& operator=(const Fraction& other);
	Fraction& operator+= (Fraction right);
	Fraction& operator-= (Fraction right);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	//                          Increment/Decrement
	Fraction& operator++();
	Fraction operator++ (int);
	Fraction& operator--();
	Fraction operator-- (int);
	//                                Type-cast operators
	explicit operator int()const;
	operator double()const;

	//                                METHODS
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;
	Fraction reduce();
	void print()const;
};
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);