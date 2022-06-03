#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-------------------------\n"
class String;
String operator+(const String& left, const String& right);

class String
{
	int size; //размер строки в байтах
	char* str; //указатель на строку
public:
	int get_size()const;
	//указатель, на который он возвращ., должен быть const
	const char* get_str()const;
	char* get_str();
	//                               Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//                             Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);
	//                             Methods
	void print()const;
};
int String::get_size()const
{
	return size;
}
const char* String::get_str()const //указатель, на который он возвращ., должен быть const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//                               Constructors
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;*/
	//Deep copy (побитовое копирование)
	//т.е. выдителить новую память и скопир. в неё содерж. другого объекта
	/*this->str = new char[size] {};*/

	//--------------------------------------------------------------------
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy(поверхностное копир.)  - MoveConstr
	/*this->size = other.size;*/
	/*this->str = other.str;*///копир. адрес памяти, пренадлежащей другому объекту
	other.size = 0;
	other.str = nullptr; //зануляем адрес памяти в другом объекте, чтобы эту
						 //память не удалил деструктор
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
//                             Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Deep copy(глубокое копирование):
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[]this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:" << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//                             Methods
void String::print()const
{
	cout << "SIZE:\t" << size << endl;
	cout << "STRING:\t" << str << endl;
	//Memory leak
}
String operator+(const String& left, const String& right)
{
	
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		/*cat.get_str()[i] = left.get_str()[i];*/
	cat[i] = left[i];
	//				l-value = r-value;
	for (int i = 0; i < right.get_size(); i++)
		/*cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	return is >> obj.get_str();
}
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
