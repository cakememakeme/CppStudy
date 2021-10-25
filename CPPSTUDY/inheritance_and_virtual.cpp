#include "stdafx.h"

class Base
{
private:
	int a = 0;
	//int e = 0;
	//int b = 0;
public:
	void BaseFunc()
	{
		std::cout << "Base Fuction" << std::endl;
	}
};

class Derived : public Base
{
private:
	char c = 0;
	//char d = 0;
public:
	void DerivedFunc()
	{
		std::cout << "Derived Function" << std::endl;
	}
};

class Third : public Derived
{
private:
	char f = 0;
public:
	void ThirdFunc()
	{
		std::cout << "Third" << std::endl;
	}
};
int main()
{
	Derived* dptr = new Derived();
	Base* bptr = dptr;
	bptr->BaseFunc();
	Base a;
	Derived b;
	Third c;
	std::cout << sizeof(a) << ' ' << sizeof(b) << ' ' << sizeof(c) << std::endl;
	return 0;
}
