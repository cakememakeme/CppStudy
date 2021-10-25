#pragma once
class Queue
{
private:
	int m_size = 0;
	int * m_queue = nullptr;
public:
	Queue();
	~Queue();
	const int front();
	const int back();
	const int size();
	const bool empty();
	void pop();
	void push(int value);
	void swap();
};

