#include "stdafx.h"
#include "ArrStack.h"
#define SAFE_DELETE_ARR(Mem) if (Mem != nullptr) delete[] Mem; Mem = nullptr;

template<typename T>
ArrStack<T>::ArrStack()
{
	m_stackArr = new T[m_capacity];
}

template<typename T>
ArrStack<T>::~ArrStack()
{
	SAFE_DELETE_ARR(m_stackArr);
}

template<typename T>
bool ArrStack<T>::Empty()
{
	if (m_stackSize == 0) return true;
	else                  return false;
}

template<typename T>
void ArrStack<T>::Push(T& PushValue)
{
	if (m_capacity > m_stackSize)
	{
		m_stackArr[m_stackSize] = PushValue;
	}
	else
	{
		T* legacyArr = m_stackArr;
		m_capacity += (m_capacity * 0.4f);
		m_stackArr = new T[m_capacity];
		std::memmove(m_stackArr, legacyArr, sizeof(T)*m_stackSize);
		m_stackArr[m_stackSize] = PushValue;
	}
	++m_stackSize;
}

template<typename T>
void ArrStack<T>::Pop()
{
	if (m_stackSize <= 0) return;

	--m_stackSize;
	m_stackArr[m_stackSize] = 0;
}

template<typename T>
void ArrStack<T>::Reserve(uint64_t& cap)
{
	if (m_stackArr == nullptr)
	{
		m_capacity = cap;
		m_stackArr = new T[m_capacity];
	}
	else
	{
		T* legacyArr = m_stackArr;
		m_capacity = cap;
		m_stackArr = new T[m_capacity];
		*m_stackArr = std::move(*legacyArr);
	}
}

template<typename T>
T ArrStack<T>::Top()
{
	if (m_stackSize > 0)
	{
		return m_stackArr[m_stackSize - 1];
	}
	else
	{
		return m_stackArr[m_stackSize];
	}
}

template<typename T>
uint64_t ArrStack<T>::Size()
{
	return m_stackSize;
}