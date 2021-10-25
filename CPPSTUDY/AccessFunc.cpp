#include "stdafx.h"
#include <iostream>


class SimpleClass
{
private:
	int num;
public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum()
	{
		return num;
	}
	void ShowNum() const
	{
		std::cout << GetNum() << std::endl;
	}
};