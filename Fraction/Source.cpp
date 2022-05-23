#include<iostream>
using namespace std;

class Fraction
{
	int integer; //выделение целой части
	int numerator; //числитель 
	int denominator; //знаменатель
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
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
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
		this->set_denominator(denominator);
		cout << " Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other) //конструктор копир
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//  OPERATORS
	//по принципу методов, при целой части
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//   Increment/Decrement
	Fraction& operator++() //prefix
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction operator++ (int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		to_proper();
		integer--;
		return *this;
	}
	Fraction operator-- (int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	
	//  METHODS
	Fraction& to_proper() //выделение целой части
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer*denominator;
		integer = 0;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	);
	return result;
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator() - right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;
}
Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);

}
//             COMPARISON OPS:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
	/*return (double)left == (double)right;*/
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	return 
		left.to_improper().get_numerator()*right.get_denominator() > right.to_improper().get_numerator()*left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator()*right.get_denominator() < right.to_improper().get_numerator()*left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

//#define CONSTRUCTORS_CHECK
#define ARITHMETICAL_CHECK
//#define COMPARISON_OPS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Def const
	A.print();

	Fraction B=7; //single
	B.print();

	Fraction C(1, 7);
	C.print();

	Fraction D(6, 8, 9);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif
#ifdef ARITHMETICAL_CHECK
	Fraction A(2, 3, 4);
	/*A.print();
	A.to_improper();
	A.print();*/
	Fraction B(19, 5);
	A.print();
	B.print();
	int a = 2;
	int b = 3;
	int c = a*b;
	Fraction C = A - B;
	C.print();
	Fraction D = ++A;
	D.print();
	Fraction E = --B;
	E.print();
	/*Fraction M = A != B;
	M.print();*/

#endif
#ifdef COMPARISON_OPS
		Fraction A(1, 4, 12);
	Fraction B(3, 300, 320);
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
#endif
}