#pragma once
struct NODE
{
	int value = 0;
	NODE* nextptr = nullptr;
};
class Single_Linked_List
{
private:
	NODE * StartPtr = nullptr;
public:
	Single_Linked_List();
	~Single_Linked_List();
	void ADD(int value);
	void FRONTADD(int value);
	void DELETE(int value);
	void PRINT();
};

