// CPPSTUDY.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
constexpr int bGame = 3;

//참조자 코드짜고 확인 (정독)

int GetrandNumb(int randNumb[bGame])//GenrandNumb 가 맞음
{

	for (int i = 0; i <= bGame; i++) randNumb[i] = 0;
	srand((int)time(NULL));
	
	//무작위 숫자
	randNumb[0] = rand() % 10;

	do {
		randNumb[1] = rand() % 10;
	} while (randNumb[1] == randNumb[0]);

	do {
		randNumb[2] = rand() % 10;
	} while (randNumb[2] == randNumb[1] || randNumb[2] == randNumb[0]);

	//지표화 불가능한 코드!
	return randNumb[bGame];
}
//참조로 넘겨야 정상적인 코드임
//매직넘버는 사용하지 말자
bool baseballGame(bool check, int randNumb[bGame])
{
	
	int inputNumb[bGame];
	int strike = 0, ball = 0, out = 0;

	

	//debug
	for (int i = 0; i <= 2; i++) printf("%d ", randNumb[i]);
	printf("\n");
	strike = 0, ball = 0, out = 0;

	//게임 시작
	while (strike != 3)
	{
		strike = 0, ball = 0, out = 0;
		//숫자 입력
		for (int i = 0; i <= 2; i++) std::cin >> inputNumb[i];

		//게임 판정
		for (int i = 0; i <= 2; i++)
		{
			if (randNumb[i] == inputNumb[i]) 				
				strike++;
			else if (randNumb[i] != inputNumb[i])
			{
				for (int j = 0; j <= 2; j++) {
					if (randNumb[i] == inputNumb[j] && i != j) ball++;
				}
			}
			else 
				out++;
		}

		//출력
		printf("%dS %dB %dO\n", strike, ball, out);

	}

	printf("Continue? 1: Yes 0: No\n");
	std::cin >> check;
	return check;
}

class classTest2
{
public:
	void PRINTF() { printf("aaaaa"); };
};

class classTest
{
public:
	classTest() { printf("create"); };

	classTest2* a;
	int b;
};


int main()
{
	classTest tt;
	tt.a = new classTest2;
	tt.b = 11111;

	tt.a->PRINTF();
	classTest aa = tt;
	aa.a->PRINTF();
	delete tt.a;
	tt.a = nullptr;

	aa.a->PRINTF();

	bool check = true;
	int randNumb[bGame] = {};

	do {
		GetrandNumb(randNumb);
		
		//int ramdomValue = GetramdNumb(????);
		//리턴값을 받아서 처리하든가, 아니면 리턴값을 없애든가
		baseballGame(check, randNumb);
	} while (check == true);

	return 0;
}
