#include "stdafx.h"
#include "Stack.h"
#include <stack>

#define SAFE_ARRAY_DELETE(dyMem) if (dyMem != nullptr) delete[] dyMem; dyMem = nullptr;


template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
Stack<T>::~Stack()
{
	SAFE_DELETE_ARRAY(m_Stack);
}

template<typename T>
const int Stack<T>::top()
{
	return *(m_Stack + (m_Size - 1));
}

template<typename T>
const int Stack<T>::size()
{
	return m_Size;
}

template<typename T>
const bool Stack<T>::empty()
{
	return m_Stack;
}

template<typename T>
void Stack<T>::push(T value)
{
	if (m_Stack == nullptr)
	{
		m_Stack = new T[++m_Size];
		*m_Stack = value;
		printf("%d\n", *m_Stack);
		printf("%d\n", m_Size);
	}
	else if (m_Stack != nullptr)
	{
		T * Temp = m_Stack;
		m_Stack = new T[m_Size + 1];
		memcpy_s(m_Stack, sizeof(T)*(m_Size),
					Temp, sizeof(T)*(m_Size));
		*(m_Stack + m_Size) = value;
		SAFE_DELETE_ARRAY(Temp);
		++m_Size;
		printf("%d\n", *(m_Stack+(m_Size-1)));
		printf("%d\n", m_Size);
	}
}

template<typename T>
void Stack<T>::pop()
{
	if (m_Stack == nullptr)
	{
		printf("empty stack\n");
		return;
	}
	else if (m_Size == 1)
	{
		SAFE_DELETE_ARRAY(m_Stack);
		m_Size = 0;
	}
	else if (m_Stack != nullptr)
	{
		T * Temp = m_Stack;
		m_Stack = new T[--m_Size];
		memcpy_s(m_Stack, sizeof(T)*(m_Size),
					Temp, sizeof(T)*(m_Size));
		SAFE_DELETE_ARRAY(Temp);
		printf("Stack : %d\n", *(m_Stack + (m_Size - 1)));
		printf("Size : %d\n", m_Size);
	}
}

template<typename T>
const void Stack<T>::swap(T other)
{
	T * Temp = other;
	other->m_Stack = m_Stack;
	other->m_Size = m_Size;
	m_Stack = Temp->m_Stack;
	m_Size = Temp->m_Size;
}

//template<typename T>
//void Stack<T>::swap(int & other)
//{
//	int * Temp = other;
//	other->m_Stack = m_Stack;
//	other->m_Size = m_Size;
//	m_Stack = Temp->m_Stack;
//	m_Size = Temp->m_Size;
//}

int main()
{
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.pop();
	Stack<int> b;
	b.push(5);
	printf("\n");
//	a.swap(b);
	printf("%d\n", a.top());
	return 0;
}