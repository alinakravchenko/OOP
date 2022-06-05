#include"Fraction.h"
//#define CONSTRUCTORS_CHECK
#define ARITHMETICAL_CHECK
//#define COMPARISON_OPS
//#define TYPE_CONVERSIONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define ISTREAM_OPERATOR_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Def const
	A.print();

	Fraction B = 7; //single
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
	Fraction A = 2.75;
	cout << A << endl;	//	2(3/4)		
#endif
#ifdef ISTREAM_OPERATOR_CHECK
		Fraction A;
		cout << "Введите дробь: ";
		cin >> A;
		cout << A << endl;
		cout << (double)A << endl;
#endif
}