#include "stdafx.h"
#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}
	int GetX() const
	{
		return xpos;
	}
	int GetY() const
	{
		return ypos;
	}
};
class Circle
{
private:
	Point pos;
	int rad;
public:
	void CircleInit(int x, int y, int radius)
	{
		pos.Init(x, y);
		rad = radius;
	}
	void ShowCircle() const
	{
		std::cout << "radius :" << rad << std::endl;
		//std::cout << "[" << pos.GetX() << "," << pos.GetY() << "]" << std::endl;
		pos.ShowPointInfo();
	}
};
class Ring
{
private:
	Circle InnerCir, OutterCir;
public:
	void Init(int ix, int iy, int irad, int ox, int oy, int orad)
	{
		InnerCir.CircleInit(ix, iy, irad);
		OutterCir.CircleInit(ox, oy, orad);
	}
	void ShowRingInfo() const
	{
		std::cout << "Inner Circle Info..." << std::endl;
		InnerCir.ShowCircle();
		std::cout << "Outter Circle Info..." << std::endl;
		OutterCir.ShowCircle();
	}
};
int main()
{
	int a(20);
	Circle cir;
	cir.CircleInit(3, 3, 9);
	cir.ShowCircle();
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	std::cout << a << std::endl;
	return 0;
}