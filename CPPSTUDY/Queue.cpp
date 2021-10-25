#include "stdafx.h"
#include "Queue.h"
//#include <queue>

#define SAFE_DELETE_ARRAY(dyMem) if(dyMem != nullptr) delete[] dyMem; dyMem = nullptr;

Queue::Queue()
{
}


Queue::~Queue()
{
	SAFE_DELETE_ARRAY(m_queue);
}

const int Queue::front()
{
	if (m_queue == nullptr) return 0;
	return *m_queue;
}

const int Queue::back()
{
	if (m_queue == nullptr) return 0;
	return *(m_queue + (m_size - 1));
}

const int Queue::size()
{
	return m_size;
}

const bool Queue::empty()
{
	return m_queue;
}

void Queue::pop()
{
	if (m_queue == nullptr)
	{
		printf("empty queue\n");
	}
	else if (m_size == 1)
	{
		SAFE_DELETE_ARRAY(m_queue);
		m_size = 0;
	}
	else if (m_queue != nullptr)
	{
		int * Temp = m_queue;
		m_queue = new int[--m_size];
		memcpy_s(m_queue, sizeof(int) * m_size, 
				Temp + 1, sizeof(int) * m_size);
		SAFE_DELETE_ARRAY(Temp);
	}

}

void Queue::push(int value)
{
	if (m_queue == nullptr)
	{
		m_queue = new int[++m_size];
		*m_queue = value;
	}
	else if (m_queue != nullptr)
	{
		int * Temp = m_queue;
		m_queue = new int[m_size + 1];
		memcpy_s(m_queue, sizeof(int) * m_size,
					Temp, sizeof(int) * m_size);
		*(m_queue + m_size) = value;
		++m_size;
		SAFE_DELETE_ARRAY(Temp);
	}
}

void Queue::swap()
{
}

int main()
{
	Queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	printf("%d %d\n", a.front(), a.back());
	printf("%d\n", a.size());
	a.pop();
	printf("%d %d\n", a.front(), a.back());
	printf("%d\n", a.size());
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	printf("%d %d\n", a.front(), a.back());
	printf("%d\n", a.size());
	return 0;
}