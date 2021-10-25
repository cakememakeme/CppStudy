#include "stdafx.h"
#include <iostream>

class FruitSeller
{
private:
	const int APPLE_PRICE; //const�� ��, ��� �̴ϼȶ����� �� ������ ���!
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
		std::cout << "���� ���: " << numOfApples << std::endl;
		std::cout << "�Ǹ� ����: " << myMoney << std::endl << std::endl;
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
			std::cout << "0���� ���� �� ���� �Ұ�" << std::endl << std::endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		std::cout << "������ " << numOfApples << "�� ���." << std::endl << std::endl;
	}
	void ShowBuyResult() const
	{
		std::cout << "���� �ܾ�: " << myMoney << std::endl;
		std::cout << "��� ����: " << numOfApples << std::endl << std::endl;
	}
	//constexpr�� ���?
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); //�޼��� ����

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}