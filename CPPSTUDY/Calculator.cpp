#include "stdafx.h"
#include <iostream>
#include "Calculator.h"

float Calculator::Add(float inputA, float inputB)
{
	++AddCount;
	return inputA + inputB;
}
float Calculator::Min(float inputA, float inputB)
{
	++MinCount;
	return inputA - inputB;
}
float Calculator::Mul(float inputA, float inputB)
{
	++MulCount;
	return inputA * inputB;
}
float Calculator::Div(float inputA, float inputB)
{
	++DivCount;
	return inputA / inputB;
}
void Calculator::Init()
{
	AddCount = 0;
	MinCount = 0;
	MulCount = 0;
	DivCount = 0;
}
void Calculator::ShowOpCount()
{
	std::cout << "µ¡¼À: " << AddCount << " »¬¼À: " << MinCount << " °ö¼À: "
		<< MulCount << " ³ª´°¼À: " << DivCount << std::endl;
}