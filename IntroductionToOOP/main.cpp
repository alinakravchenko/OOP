#include<iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};
void main()
{
	setlocale(LC_ALL, "");
	//type name;
	int a; //объ€вление пременной 'a' типа 'int'
	Point A;//объ€вление пременной 'A' типа или структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//вариант 2: cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << sizeof(Point) << endl;
}