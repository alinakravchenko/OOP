﻿#pragma warning (disable:4326)
#include<iostream>
using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
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
	explicit Fraction(int integer) //целая часть
		//явный, запрещает неявные преобразования типов
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
	//                                 OPERATORS
	//по принципу методов, при целой части
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+= (Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator + right.numerator*this->denominator;
		this->denominator = this->denominator*right.denominator;
		return *this;
	}
	Fraction& operator-= (Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator - right.numerator*this->denominator;
		this->denominator = this->denominator*right.denominator;
		return *this;
	}
	/*Fraction& operator*=(Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.numerator;
		this->denominator = this->denominator*right.denominator;
		return *this;

	}*/
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	/*Fraction& operator/=(Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator;
		this->denominator = this->denominator*right.numerator;
		return *this;
	}*/
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//                          Increment/Decrement
	Fraction& operator++() //prefix
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction operator++ (int)
	{
		Fraction old = *this;	//Сохраняем текущее состояние объекта
		to_proper();
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
		to_proper();
		integer--;
		return old;
	}
	//                                Type-cast operators
	explicit operator int()const
	{
		return integer;
	}
 operator double()const
	{
		return integer + (double)numerator / denominator;
	}
 Fraction(double dec)
 {
	 dec += 1e-10; //при 75999999, чтобы убрать девятки
	 integer = dec; //сохранение целой части 
	 dec -= integer; //убираем целую часть из дроби 
	 denominator = 1e+9; // 9 степень
	 numerator = dec * denominator;
	 cout << "Homework:\t" << this << endl;

 }
	//                                METHODS
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
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;

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
	/*return left.to_improper()*right.inverted();*/
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
//                                 COMPARISON OPS:
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
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();	//Если есть целая часть, выводим ее на экран
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	 if (obj.get_integer() == 0&&obj.get_numerator()==0)os << 0;
	return os;
}
//istream& operator>>(istream& is, fraction& obj)
//{
//	const int size = 50;
//	char buffer[size] = {};
//	char delimiter[] = "()/. ";//https://www.cplusplus.com/reference/cstring/strtok/
//	is >> buffer; //ввод строки
//	char* value[3] = {}; //создаём массив 
//						
//}
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_CHECK
//#define COMPARISON_OPS
//#define TYPE_CONVERSIONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER
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
	Fraction C = A * B;
	C.print();
	(A / B).print();
	(A + B).print();
	(A - B).print();
	/*Fraction D = ++A;
	D.print();
	Fraction E = --B;
	E.print();*/
	
	
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
	/*cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;*/
#endif
	/*Fraction A(1, 2);

	cout << A << endl;*/
	/*Fraction A;
	cout<<"Введите простую дробь: "
	cin >> A;
	cout << A << endl;*/
#ifdef TYPE_CONVERSIONS_BASE
	cout << typeid(7 / .2).name() << endl;
	int a = 2;		//No conversions
	double b = 3;	//Conversion from int to double.
					//			 from less to more.

	int c = b;		//Conversion from double to int
					//			 from more to less without data loss
	int d = 5.5;	//Conversion from double to int
					//			 from more to less with data loss
#endif
	#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

	/*Fraction A = 5;
	cout << A << endl; *///From int to Fraction	(from less to more)
	Fraction B; //Default constructor
	cout << "\n---------\n";
	/*B = 8;*/  B = Fraction(8);   //Conversion from int to Fraction
	cout << "\n---------\n";
	cout << B << endl;
	cout << "\n---------\n";
	Fraction C(12);	//explicit конструктор можно вызвать так, нельзя вызвать: Fraction C = 12;
	cout << C << endl;
#endif
	/*
	operator type()
	{
	//   conversion code;
	}
	*/
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	/*Fraction A(2, 3, 4);
	int a = (int) A;
	cout << a << endl;
	double b = A;
	cout << b << endl;*/
	Fraction A = 2.76;
		cout << A << endl;	//	2(3/4)		
#endif
}