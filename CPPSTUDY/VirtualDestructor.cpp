#include "stdafx.h"
#include <iostream>
/*
class First
{
private:
	char * strOne;
public:
	First(const char * str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First()
	{
		std::cout << "~First()" << std::endl;
		delete []strOne;
	}
};

class Second : public First
{
private:
	char * strTwo;
public:
	Second(const char * str1,const char * str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()
	{
		std::cout << "~Second()" << std::endl;
		delete []strTwo;
	}
};

int main()
{
	First * ptr = new Second("simple", "complex"); // 왱
	delete ptr;
	return 0;
}
*/

class First
{
public:
	void FirstFunc() { std::cout << "FirstFunc()" << std::endl; }
	virtual void SimpleFunc() { std::cout << "First's SimpleFunc()" << std::endl; }
};

class Second : public First
{
public:
	void SecondFunc() { std::cout << "SecondFunc()" << std::endl; }
	virtual void SimpleFunc() { std::cout << "Second's SimpleFunc()" << std::endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { std::cout << "ThirdFunc()" << std::endl; }
	virtual void SimpleFunc() { std::cout << "Third's SimpleFunc()" << std::endl; }
};

int main()
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second & sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	Third test;
	test.SimpleFunc();
	std::cout << std::endl;

	First & fref = obj;
	fref.FirstFunc();
	//fref.ThirdFunc();
	fref.SimpleFunc();
	
	printf("%d %d", sizeof(test), sizeof(fref));

	std::string str("dd");
	str = "dddd";
}
//p488 펑터
//펑터가 있긴 한데 저러한 예의 사용은 직관적이지 않은 것 같다.

//p530 컴파일 할 때 함수가 만들어지면 속도가 느려진다, 실행 시 느려지는 경우는?