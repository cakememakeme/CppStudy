#pragma once
template<typename T>
class Stack
{
private:
	int m_Size = 0;
	T * m_Stack = nullptr; //arr 관리용인데 이름이 모호함
									 //구현 방식(노드, 배열)에 따른 변수 이름 재지정 필요
	//T * m_dynamic_Arr_Ptr = nullptr; //arr 관리용인데 이름이 모호함
	//								 //구현 방식(노드, 배열)에 따른 변수 이름 재지정 필요

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

