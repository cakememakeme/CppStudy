#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

class String
{
	int len;
	char * str;
public:
	String()
	{
		len = 0;
		str = nullptr;
	}
	String(const char * s)
	{
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	String(const String& s)
	{
		len = s.len;
		str = new char[len];
		strcpy(str, s.str);
	}
	~String()
	{
		if (str != nullptr)
			delete[] str;
	}
	String& operator = (const String& s)
	{
		if (str != nullptr)
			delete[]str;
		len = s.len;
		str = new char[len];
		strcpy(str, s.str);
		return *this;
	}

	String& operator+= (const String& s)
	{
		len += (s.len - 1);
		char* tempstr = new char[len];
		strcpy(tempstr, str);
		strcat(tempstr, s.str);

		if (str != nullptr)
			delete[] str;
		str = tempstr;
		return *this;
	}

	bool operator== (const String& s)
	{
		return strcmp(str, s.str) ? false : true;
	}

	String operator+ (const String& s)
	{
		char* tempstr = new char[len + s.len - 1];
		strcpy(tempstr, str);
		strcat(tempstr, s.str);

		String temp(tempstr);
		delete[]tempstr;
		return temp;
	}

	friend ostream& operator<< (ostream& os, const String& s)
	{
		os << s.str;
		return os;
	}

	friend istream& operator>> (istream& is, String& s)
	{
		char str[100];
		is >> str;
		s = String(str);
		return is;
	}
};

int main()
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
}