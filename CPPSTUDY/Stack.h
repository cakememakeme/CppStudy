#pragma once
template<typename T>
class Stack
{
private:
	int m_Size = 0;
	T * m_Stack = nullptr; //arr �������ε� �̸��� ��ȣ��
									 //���� ���(���, �迭)�� ���� ���� �̸� ������ �ʿ�
	//T * m_dynamic_Arr_Ptr = nullptr; //arr �������ε� �̸��� ��ȣ��
	//								 //���� ���(���, �迭)�� ���� ���� �̸� ������ �ʿ�

public:
	Stack();
	~Stack();
	const int top();
	const int size();
	const bool empty();
	void push(T value);
	void pop();
	const void swap(T other);
//	void swap(int & other);
};

