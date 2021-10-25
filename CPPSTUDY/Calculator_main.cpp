#include "stdafx.h"
#include <iostream>
#include "Calculator.h"

int add(int a, int b)
{
	return a + b;
};

int main()
{
	std::cout << add(5, 7) << std::endl;
	Calculator cal;
	cal.Init();
	std::cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << std::endl;
	//상수참조가 안된다고 하지 않았었나?
	//배열과 같은 포인터형은 메모리 접근이 가능해지는 경우가 생겨서 안됨
	std::cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << std::endl;
	std::cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << std::endl;
	std::cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;
	cal.ShowOpCount();
	return 0;
}