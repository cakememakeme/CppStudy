#pragma once

#include <stdlib.h>
#include <iostream>

template <typename T>
constexpr void SAFE_DELETE_ARR(T * Mem)
{
	if (Mem == nullptr)
	{
		return;
	}
	delete[] Mem;
}

void error()
{
	exit(EXIT_FAILURE);
}

template <typename T>
class FixedDeque
{
public:
	FixedDeque<T>() = delete;
	FixedDeque<T>(size_t size)
		: _maxSize(size), _usage(0), _front(0), _rear(1)
	{
		_values = new T[size];
	}
	~FixedDeque<T>()
	{
		SAFE_DELETE_ARR(_values);
	}

	void PushBack(const T& value)
	{
		if (isFull())
		{
			error();
		}

		_values[_rear] = value;
		_rear = (_rear + 1) % _maxSize;
		++_usage;
	}

	void PushFront(const T& value)
	{
		if (isFull())
		{
			error();
		}

		_values[_front] = value;
		_front = ((_front - 1) + _maxSize) % _maxSize;
		++_usage;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			error();
		}

		_rear = ((_rear - 1) + _maxSize) % _maxSize;
		--_usage;
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			error();
		}

		_front = (_front + 1) % _maxSize;
		--_usage;
	}

	const T& Front()
	{
		int front = (_front + 1) % _maxSize;
		return _values[front];
	}

	const T& Back()
	{
		int rear = ((_rear - 1) + _maxSize) % _maxSize;
		return _values[rear];
	}

	bool IsEmpty()
	{
		if (0 == _usage)
		{
			return true;
		}
		return false;
	}

	void Print()
	{
		for (int i = 0; i < _maxSize; ++i)
		{
			std::cout << _values[i] << ' ';
		}
		std::cout << '\n';
	}

public:
	bool isFull()
	{
		if (_usage == _maxSize)
		{
			return true;
		}
		return false;
	}

private:
	T* _values;
	size_t _maxSize;
	size_t _usage;
	size_t _front;
	size_t _rear;
};

