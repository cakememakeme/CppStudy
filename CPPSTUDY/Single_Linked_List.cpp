#include "stdafx.h"
#include "Single_Linked_List.h"



void Single_Linked_List::ADD(int value)
{
	if (StartPtr == nullptr)
	{
		StartPtr = new NODE;
		StartPtr->value = value;
		StartPtr->nextptr = nullptr;
	}
	else
	{
		NODE * Temp = nullptr;
		Temp = StartPtr;
		while (1)
		{
			if (Temp->nextptr == nullptr)
			{
				NODE * Temp1 = new NODE;
				Temp1->value = value;
				Temp1->nextptr = nullptr;

				Temp->nextptr = Temp1;
				break;
			}
			else
			{
				Temp = Temp->nextptr;
			}

		}
	}
}

void Single_Linked_List::FRONTADD(int value)
{
	if (StartPtr == nullptr)
	{
		StartPtr = new NODE;
		StartPtr->value = value;
		StartPtr->nextptr = nullptr;
	}
	else
	{
		NODE * FrontPtr = new NODE;
		FrontPtr->value = value;
		FrontPtr->nextptr = StartPtr;
		StartPtr = FrontPtr;
	}
}

void Single_Linked_List::DELETE(int value)
{
	NODE * PreTemp = nullptr;
	NODE * Temp = nullptr;
	NODE * NextTemp = nullptr;
	Temp = StartPtr;

	while (1)
	{
		if (Temp->value == value)
		{

			if (PreTemp == nullptr)
			{
				if (Temp->nextptr == nullptr) //값이 하나일 때
				{
					delete Temp;
					StartPtr = nullptr;
					break;
				}
				else //맨처음일때
				{
					NextTemp = Temp->nextptr;
					delete Temp;
					StartPtr = NextTemp;
					break;
				}
			}
			else if (Temp->nextptr == nullptr) //맨마지막
			{
				PreTemp->nextptr = nullptr;
				delete Temp;
				break;
			}
			else //중간
			{
				NextTemp = Temp->nextptr;
				PreTemp->nextptr = NextTemp;
				delete Temp;
				break;
			}
		}
		else //값이 안걸렸을때
		{
			PreTemp = Temp;
			Temp = Temp->nextptr;
		}
	}
}

void Single_Linked_List::PRINT()
{
	NODE * Temp = nullptr;
	if (StartPtr == nullptr)
	{
		printf("empty\n");
		return;
	}
	Temp = StartPtr;
	while (1)
	{
		printf("%d\n", Temp->value);
		if (Temp->nextptr == nullptr)
		{
			break;
		}
		Temp = Temp->nextptr;
	}
}

Single_Linked_List::Single_Linked_List()
{
}


Single_Linked_List::~Single_Linked_List()
{
}
int main()
{
	Single_Linked_List A;
	A.FRONTADD(0);
	A.FRONTADD(-1);
	A.ADD(1);
	printf("-1 0 1 \n");
	A.PRINT();
	A.DELETE(1);
	printf("-1 0 \n");
	A.PRINT();
	A.ADD(1);
	A.ADD(2);
	printf("-1 0 1 2\n");
	A.PRINT();
	A.DELETE(1);
	printf("-1 0 2\n");
	A.PRINT();
	return 0;
}