// TestProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

//#include <cstdio>
#include <chrono>
#include <string>
#include <vector>

namespace {
	void on_stack()
	{
		int i;
	}

	void on_heap()
	{
		int* i = new int;
		delete i;
	}
}

class A
{
public:
	A(const char* name, int age)
		: _age(age)
	{
		_name = new char[strlen(name) + 1];
		memcpy(_name, name, strlen(name) + 1);
	}
	A(const A& copy)
		: _age(copy._age)
	{
		_name = new char[strlen(copy._name) + 1];
		memcpy(_name, copy._name, strlen(copy._name) + 1);
	}
//	A& 
	~A()
	{
		std::cout << &_name << std::endl;
		std::cout << _name << std::endl;
		delete[] _name;
	}
private:
	char* _name;
	int _age;
};

class SoSimple
{
	//static int num1 = 0;
	int num2 = 0;
public:
	SoSimple(int n) : num2(n)
	{ }
	void ShowData() const
	{
		std::cout << num2 << std::endl;
	}
	void AddNum(int n)
	{
		num2 += n;
	}
};

int add(int first, int second)
{
	return first + second;
}

int calculator(int first, int second, int(*func) (int, int))
{
	return func(first, second);     // 함수포인터의 사용
}

void stt(int num)
{
	static int a = 10;
	a += num;
	std::cout << a << std::endl;
}

int main()
{
	int(*FuncPtr) (int, int) = nullptr;
	FuncPtr = add;
	int addf = FuncPtr(1, 2);
	calculator(3, 4, FuncPtr);
	std::cout << sizeof(&stt) << ' ' <<
		sizeof(&FuncPtr) << std::endl;
	std::cout << &stt << std::endl << stt << std::endl;
	stt(0);
	stt(5);
	stt(5);
	return 0;
}

	//auto begin = std::chrono::system_clock::now();
	//for (int i = 0; i < 100000000; ++i)
	//	on_stack();
	//auto end = std::chrono::system_clock::now();

	//std::printf("on_stack took %f seconds\n", std::chrono::duration<double>(end - begin).count());

	//begin = std::chrono::system_clock::now();
	//for (int i = 0; i < 100000000; ++i)
	//	on_heap();
	//end = std::chrono::system_clock::now();

	//std::printf("on_heap took %f seconds\n", std::chrono::duration<double>(end - begin).count());
	//return 0;
/*
결과
on_stack took 0.241013 seconds
on_heap took 15.513888 seconds*/
