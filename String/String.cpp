#include"String.h"
int String::get_size()const
{
	return size;
}
const char* String::get_str()const //���������, �� ������� �� �������., ������ ���� const
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
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	/*this->size = other.size;*/
	//Deep copy (��������� �����������)
	//�.�. ���������� ����� ������ � ������. � �� ������. ������� �������
	/*this->str = new char[size] {};*/

	//--------------------------------------------------------------------
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy(������������� �����.)  - MoveConstr
	/*this->size = other.size;*/
	/*this->str = other.str;*///�����. ����� ������, ������������� ������� �������
	other.size = 0;
	other.str = nullptr; //�������� ����� ������ � ������ �������, ����� ���
						 //������ �� ������ ����������
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
	//Deep copy(�������� �����������):
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