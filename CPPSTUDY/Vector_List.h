#pragma once
#include <iostream>
#include <memory.h>
template <typename T>
class MyVec
{
private:
	int myCap = 0;
	int mySize = 0;
	T * Vec = nullptr;
public:
	MyVec(T n);
	MyVec(const std::initializer_list<T> & n);
	MyVec();
	~MyVec();
	int size();
	int capacity();
	void print();
	void popback();
	void pushback(T n);
	void reserve(int n);
	void sort();
	void mergeSort();
};
