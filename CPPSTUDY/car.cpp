#include "stdafx.h"
#include <iostream>
#include <cstring>

class Car
{
	enum
	{
		ID_LEN = 20, MAX_SPD = 200, FULE_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
private:
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char * ID, int fuel)
{
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}
void Car::ShowCarState()
{
	std::cout << "소유자 ID: " << gamerID << std::endl;
	std::cout << "연료량 :" << fuelGauge << "%" << std::endl;
	std::cout << "현재속도 :" << curSpeed << "km/s" << std::endl;
}
void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= FULE_STEP;

	if ((curSpeed + ACC_STEP) >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
		return;
	}
	curSpeed += ACC_STEP;
}
void Car::Break()
{
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= BRK_STEP;
}

int main()
{
	Car run99;
	run99.InitMembers("run99", 100); //?
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}