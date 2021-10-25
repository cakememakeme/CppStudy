#include "stdafx.h"
#include <iostream>

class FruitSeller
{
private:
	const int APPLE_PRICE; //const일 때, 멤버 이니셜라이저 및 생성자 사용!
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		std::cout << "남은 사과: " << numOfApples << std::endl;
		std::cout << "판매 수익: " << myMoney << std::endl << std::endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller & seller, int money)
	{
		if (money < 0)
		{
			std::cout << "0보다 작은 수 전달 불가" << std::endl << std::endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		std::cout << "과일을 " << numOfApples << "개 샀다." << std::endl << std::endl;
	}
	void ShowBuyResult() const
	{
		std::cout << "현재 잔액: " << myMoney << std::endl;
		std::cout << "사과 개수: " << numOfApples << std::endl << std::endl;
	}
	//constexpr은 어떻게?
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); //메세지 전달

	std::cout << "과일 판매자의 현황" << std::endl;
	seller.ShowSalesResult();
	std::cout << "과일 구매자의 현황" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}