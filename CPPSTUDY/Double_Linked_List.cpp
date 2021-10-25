#include "stdafx.h"
#include "Double_Linked_List.h"


Double_Linked_List::Double_Linked_List()
{
}


Double_Linked_List::~Double_Linked_List()
{
}

void Double_Linked_List::ADD(int value)
{
	if (StartPtr == nullptr)
	{
		StartPtr = new NODE;
		StartPtr->value = value;
		StartPtr->nextptr = nullptr;
		StartPtr->preptr = nullptr;
	}
	else
	{
		NODE * Temp;
		Temp = StartPtr;
		while (Temp->nextptr != nullptr)
		{
			Temp = Temp->nextptr;
		}

		NODE * Ptr = new NODE;
		Temp->nextptr = Ptr;

		Ptr->value = value;
		Ptr->nextptr = nullptr;
		Ptr->preptr = Temp;
	}
}

void Double_Linked_List::FRONTADD(int value)
{
	if (StartPtr == nullptr)
	{
		StartPtr = new NODE;
		StartPtr->value = value;
		StartPtr->nextptr = nullptr;
		StartPtr->preptr = nullptr;
		return;
	}
	NODE * Temp;
	Temp = StartPtr;

	NODE * Ptr = new NODE;
	Ptr->value = value;
	Ptr->nextptr = Temp;
	Ptr->preptr = nullptr;
	
	Temp->preptr = Ptr;
	StartPtr = Ptr;
}

void Double_Linked_List::DELETE(int value)
{
	if (StartPtr == nullptr)
	{
		printf("empty\n");
		return;
	}
	if (StartPtr->nextptr == nullptr) //처음
	{
		//delete[] Temp; // StartPtr을 지워버리는게 아닌건가?
		//delete[] StartPtr // 이것 역시?
		delete[] StartPtr; //이러면 되네
		StartPtr = nullptr;
		return;
		//세이프 딜리트 사용
	}

	NODE * Temp;
	Temp = StartPtr;
	while (Temp->value != value)
	{
		Temp = Temp->nextptr;
	}
	if (Temp->nextptr != nullptr && Temp->preptr == nullptr) //처음2
	{
		StartPtr = Temp->nextptr;
		Temp = nullptr;
		delete[] Temp;
		return;
	}
	if (Temp->nextptr != nullptr) //중간
	{
		(Temp->preptr)->nextptr = Temp->nextptr;
		Temp = nullptr;
		delete[] Temp;
		return;
	}
	if (Temp->nextptr == nullptr) //끝
	{
		(Temp->preptr)->nextptr = nullptr;
		Temp = nullptr;
		delete[] Temp;
		return;
	}
}

void Double_Linked_List::PRINT()
{
	if (StartPtr == nullptr)
	{
		printf("empty\n");
	}
	else
	{
		NODE * Temp;
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
}

void Double_Linked_List::REVPRINT()
{
	if (StartPtr == nullptr)
	{
		printf("empty\n");
		return;
	}
	NODE * Temp;
	Temp = StartPtr;
	while (Temp->nextptr != nullptr)
	{
		Temp = Temp->nextptr;
	}
	while (1)
	{
		printf("%d\n", Temp->value);
		if (Temp->preptr == nullptr)
		{
			break;
		}
		Temp = Temp->preptr;
	}
}

int main()
{
	Double_Linked_List A;
	A.ADD(1);
	A.FRONTADD(0);
	A.ADD(2);
	A.FRONTADD(-1);
	A.REVPRINT();
	printf("\n");
	A.PRINT();
	return 0;
}