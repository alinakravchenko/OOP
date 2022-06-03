#pragma once
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
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
