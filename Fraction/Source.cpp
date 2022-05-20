#include<iostream>
using namespace std;

class Fraction
{
	int integer; //выделение целой части
	int numerator; //числитель 
	int denominator; //знамен.
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	/*задаём знач. переменных*/
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = denominator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << " DefaultConstructor:\t " << this << endl;
	}
	Fraction(int integer) //целая часть
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << " Single argument constructor:" << this << endl;
	}
	Fraction(int numerator, int denominator) //дробная часть
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << " Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->denominator = numerator;
		this->numerator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other) //конструктор копир
	{
		this->integer = other.integer;
		this->denominator = other.denominator;
		this->numerator = other.numerator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//по принципу методов, при целой части
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->denominator = other.denominator;
		this->numerator = other.numerator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//void simple_fraction() //выделение целой части
	//{
	//	integer += numerator / denominator;
	//	numerator %= denominator;
	//}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		cout << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Fraction A; //Def const
	A.print();
	Fraction B(7); //single
	B.print();
	Fraction C(1, 7);
	C.print();
	Fraction D(6, 8, 9);
	D.print();
	/*Fraction A(18, 9);
	A.simple_fraction();
	A.print();*/


}