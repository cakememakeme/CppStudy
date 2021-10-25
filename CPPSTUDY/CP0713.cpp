#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

//128

int& RefRetFuncOne(int &ref) //�̰� �� Ȱ�뼺�� �����ϱ� �̷��� �ϴ°� �� ������?  p.88
{
	ref++;
	return ref;
}
//��ȯ���� ������� ��ȯ�� �޴� ���� ���� �������� �ϴ°� �ƴѰɱ�?
//�̰� ������ �´ٸ� �� ����
/*
int RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}*/
//�̷��� ���� ��������...?


int Adder(const int num3, const int num4)
{
	return num3 + num4;
}

typedef struct __Point//Point�� __Point�� ����?
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
	//�������� �̷��� ����ؾ� �ϴ� ������ �ñ�

	std::cout << Adder(3, 4) << std::endl;

	const int Qnum = 12;	
	const int * Pnum = &Qnum;
	const int *(&Rnum) = Pnum;//????? ���� ������? ������ ����?

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
	delete &pref; // �Լ� ���� �� �޸� ����?
	

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
