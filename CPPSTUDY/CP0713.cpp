#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

//128

int& RefRetFuncOne(int &ref) //이게 더 활용성이 좋으니까 이렇게 하는게 더 좋은가?  p.88
{
	ref++;
	return ref;
}
//반환형이 참조라면 반환을 받는 변수 또한 참조여야 하는게 아닌걸까?
//이게 문법상 맞다면 왜 굳이
/*
int RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}*/
//이렇게 하지 않은건지...?


int Adder(const int num3, const int num4)
{
	return num3 + num4;
}

typedef struct __Point//Point와 __Point의 차이?
{
	int xpos;
	int ypos;
} Point;

typedef struct Point
{
	int xpos;
	int ypos;

	void MovePos(int x, int y);
	void AddPoint(const Point& pos);
	void ShowPosition();
	void ShowWorld();
};
void Point::ShowWorld()
{
	std::cout << "Hello World!" << std::endl;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point * pptr = new Point;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p2.ypos + p2.ypos;
	return *pptr;
}

int main()
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);

	const int num = 20;
	const int &ref = num;
	//참조형을 이렇게 사용해야 하는 이유가 궁금

	std::cout << Adder(3, 4) << std::endl;

	const int Qnum = 12;	
	const int * Pnum = &Qnum;
	const int *(&Rnum) = Pnum;//????? 이중 포인터? 포인터 참조?

	/*
	int *ptr = new int;
	int &Rref = *ptr;
	Rref = 200;
	std::cout << *ptr << std::endl;
	*/

	
	Point *pptr1 = new Point;
	pptr1->xpos = 1;
	pptr1->ypos = 1;

	Point *pptr2 = new Point;
	pptr2->xpos = 2;
	pptr2->ypos = 2;
	
	Point &pref = PntAdder(*pptr1, *pptr2);
	std::cout << "[" << pref.xpos << ", " << pref.ypos << "]" << std::endl;
	std::cout << std::endl;

	 pptr1;
	delete pptr2;
	delete &pref; // 함수 안의 힙 메모리 때문?
	

	char str1[] = "abcd efgh";
	char str2[50];
	char str3[] = "ijkl mnop";
	int strnum = strlen(str1);
	strcpy_s(str2, str1);
	std::cout << strnum << str2 << std::endl;
	strcat_s(str2, str3);
	std::cout << str2 <<std::endl;

	num1 += 1;
	num2 ++;
	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;

	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	pos1.ShowWorld();

	return 0;
}

void Point::MovePos(int x, int y)
{
	xpos += x;
	ypos += y;
}

void Point::AddPoint(const Point &pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;
}

void Point::ShowPosition()
{
	std::cout << xpos << " " << ypos << std::endl;
}
