#include<iostream>
using namespace std;
//sqrt(square root) - квадратный корень
using std::cin;
using std::cout;
using std::endl;

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
	//      Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultContructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//     HomeWork Methods
	double distance(Point dot) //принимает точку
	{
		//выч. расстояние по х
		double x_distance = dot.x - this->x;
		//выч. расстояние по y
		double y_distance = dot.y - this->y;
		double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
		return distance; //задание 1
		                     
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
//задание 2
double distance(Point A, Point B)  //возвращает две точки
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance*y_distance);
	return distance;
}
//#define STRUCT_POINT
//#define DISTANCE
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
#ifdef DISTANCE

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до В: " << A.distance(B) << endl;
	cout << "Расстояние МЕЖДУ А и В: " << distance(A,B) << endl;
#endif
	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << "\t";
	cout << endl;*/
	int a;
	/*cout << a << endl;*/

	Point A; //Default constructor
	/*cout << A.get_x() << "\t" << A.get_y() << endl;*/
	A.print();
}