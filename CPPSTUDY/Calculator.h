#pragma once

class Calculator
{
private:
	int AddCount = 0, MinCount, //private�ε� �� �ʱ�ȭ�� ++������ �����Ѱ���?
		MulCount, DivCount; //���� Calculator Ŭ���� ���ζ� �����ߴ���
	//Ŭ���� ������� ������ �ʱ�ȭ�� ������� �ʴ´ٰ� �� p.141
	const int APPLE = 1000;
	//�ٵ��ߵ�...
public:
	void Init();
	void ShowOpCount();
	float Add(float inputA, float inputB);
	float Min(float inputA, float inputB);
	float Mul(float inputA, float inputB);
	float Div(float inputA, float inputB);
};