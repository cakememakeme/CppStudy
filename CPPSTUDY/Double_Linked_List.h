#pragma once
struct NODE
{
	int value = 0;
	NODE* preptr = nullptr;
	NODE* nextptr = nullptr;
};
class Double_Linked_List
{
private:
	NODE * StartPtr = nullptr;
public:
	Double_Linked_List();
	~Double_Linked_List();
	void ADD(int value);
	void FRONTADD(int value);
	void DELETE(int value);
	void PRINT();
	void REVPRINT();
};