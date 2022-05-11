﻿#include<iostream>
using namespace std;



class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};
//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a; //объявление пременной 'a' типа 'int'
	Point A;//объявление пременной 'A' типа или структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//вариант 2: cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << sizeof(Point) << endl;
#endif
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

}