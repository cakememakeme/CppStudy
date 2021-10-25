#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class MyString
{
private:
	int m_strLength = 0;
	int m_strCapacity = 0;
	char * m_strString = nullptr;
public:
	MyString(const char * str);
	MyString();
	~MyString();
	char * Show();
	int Length();
	int Size();
	int Capacity();
	void Clear();
	bool operator==(const MyString & str);
	MyString operator+(const MyString & str);
	friend std::ostream& operator<< (std::ostream& os, const MyString& str);
	friend bool strcmp( MyString& str1, MyString& str2);
};
bool strcmp( MyString& str1, MyString& str2);
