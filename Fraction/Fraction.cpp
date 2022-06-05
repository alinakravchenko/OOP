#include"Fraction.h"



int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
/*задаём знач. переменных*/
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << " DefaultConstructor:\t " << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << " Single argument constructor:" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) //дробная часть
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << " Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t" << this << endl;
}

Fraction::Fraction(const Fraction& other) //конструктор копир
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}
//                                 OPERATORS
//по принципу методов, при целой части
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator+= (Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.denominator + right.numerator*this->denominator;
	this->denominator = this->denominator*right.denominator;
	return *this;
}
Fraction& Fraction::operator-= (Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.denominator - right.numerator*this->denominator;
	this->denominator = this->denominator*right.denominator;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this*other;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

//                          Increment/Decrement
Fraction& Fraction::operator++() //prefix
{
	to_proper();
	integer++;
	return *this;
}
Fraction Fraction::operator++ (int)
{
	Fraction old = *this;	//Сохраняем текущее состояние объекта
	to_proper();
	integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	to_proper();
	integer--;
	return *this;
}
Fraction Fraction::operator-- (int)
{
	Fraction old = *this;
	to_proper();
	integer--;
	return old;
}
//                                Type-cast operators
Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//                                METHODS
Fraction&  Fraction::to_proper() //выделение целой части
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	numerator += integer*denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;

}
Fraction Fraction::reduce()
{
	int more;	//Большее значение
	int less;	//Меньшее значение
	int rest;	//Остаток от деления
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		less = numerator;
		more = denominator;
	}
	do
	{
		rest = more%less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;	//GCD - Greatest Common Divisor (Наибольший общий делитель)
	if (GCD == 0)return *this;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
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
Fraction operator*(Fraction left, Fraction right)
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
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	/*cin >> buffer;*/ //ввод строки
	cin.getline(buffer, SIZE);
	char delimiters[] = "()/ ";//https://www.cplusplus.com/reference/cstring/strtok/
	char* sz_numbers[3] = {}; //создаём массив 
	int i = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{

		sz_numbers[i++] = pch;
	}
	switch (i)
	{
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
		//http://cplusplus.com/reference/cstdlib/atoi/
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3:
		obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));
	}
	return is;


}
