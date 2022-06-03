#include"String.h"
#include<iostream>

//#define CONSTR_CHECK
//#define MOVE_METHODS_CHECK
//#define CONSTR_TWO_CHECK
void main()
{
	setlocale(LC_ALL, "");
	#ifdef	CONSTR_CHECK
	String str; //DefaultConstructor
	str.print();

	String str2(5); //explicit Single Argument constr
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3; //CopyConstr
	str4.print();

	String str5;//CopyAssignment
	str5.print();
	str5 = str4;
	str5.print();
#endif
#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2("World");
	cout << str2 << endl;
	/*String str3 = str1 + str2;*/ //MoveConstructor
	String str3;
	str3 = str1 + str2;
	//str3.print();
	cout << delimiter << endl;
	cout << str3 << endl;
#endif
#ifdef CONSTR_TWO_CHECK
	String str1 = "Hello";
	String str2("World");
	str1 += str2;
	cout << str1 << endl;
	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;
#endif
	String str1;
	str1.print();
	String str2(55);
	str2.print();
	String str3 = "Hello";
	String str4 = str3;
	String str6();
	String str7{};
	str7.print();
	cout << str4 << endl;

}
