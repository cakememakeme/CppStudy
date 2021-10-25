#pragma once

class Calculator
{
private:
	int AddCount = 0, MinCount, //private인데 왜 초기화랑 ++같은게 가능한거지?
		MulCount, DivCount; //같은 Calculator 클래스 내부라서 가능했던것
	//클래스 멤버변수 선언문은 초기화를 허용하지 않는다고 함 p.141
	const int APPLE = 1000;
	//근데잘됨...
public:
	void Init();
	void ShowOpCount();
	float Add(float inputA, float inputB);
	float Min(float inputA, float inputB);
	float Mul(float inputA, float inputB);
	float Div(float inputA, float inputB);
};