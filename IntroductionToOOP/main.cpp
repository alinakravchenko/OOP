#include<iostream>
using namespace std;
//sqrt(square root) - квадратный корень
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------\n"
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
	/*Point()
	{
		x = y = 0;
		cout << "DefaultContructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this-> x = x;
		this->y = y;
		cout << "Single argument constructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	//Class(const Class& other);
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" <<this<< endl;
	}

	~Point() //заканчивает секцию конструкторов 
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//     Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//     HomeWork Methods
	double distance(const Point& dot) //принимает точку
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
double distance(const Point& A, const Point& B)  //возвращает две точки
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	/*A.set_x(-10);*/
	double distance = sqrt(x_distance*x_distance + y_distance*y_distance);
	return distance;
}
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK1
#define ASSIGNMENT_CHECK2
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
	cout << delimiter << endl;
	cout << "Расстояние от точки А до В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние МЕЖДУ А и В: " << distance(A,B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние МЕЖДУ B и A: " << distance(B,A) << endl;
#endif
#ifdef CONSTRUCTORS_CHECK
	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << "\t";
	cout << endl;*/
	int a(2);
	cout << a << endl;

	Point A; //Default constructor
	/*cout << A.get_x() << "\t" << A.get_y() << endl;*/
	A.print();

	Point B = 5; //SingleArgumentConstructor
	B.print();

	Point C(8); //SingleArgumentConstructor
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D; //CopyConstructor
	E.print();

	Point F(D); //CopyConstructor
	F.print();
#endif
#ifdef ASSIGNMENT_CHECK1
	//CopyAssignment
	Point A(2, 3);
	Point B = A;  //CopyConstructor потому что объект 'B' создается 
	Point C; //Default Constructor
	C = B; //CopyAssignment потому что объект 'С' уже существует
#endif
	int a, b, c;

	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
}