#include "stdafx.h"
#include <stack>
#include <queue>
#include <unordered_map>
#include "Vector_List.h"
// { } 를 쓰고싶어서
//https://github.com/abiles/gameServer2015/wiki/Item-7-:-객체를-만들-때-()과-%7B%7D를-구분하자
//참고함
//http://narss.tistory.com/entry/5일차-initializerlist

template<typename T>
MyVec<T>::MyVec(T n)
{
	++myCap;
	++mySize;
	Vec = new T[myCap];
	*Vec = n;
}

template<typename T>
MyVec<T>::MyVec(const std::initializer_list<T> & n)
{
	mySize = n.size();
	myCap = mySize * 1.2;
	Vec = new T[myCap];
	std::initializer_list<int>::iterator p = n.begin(); // 이게뭐지?
	
	int i = 0;
	while ((p + i) != n.end())
	{
		*(Vec + i) = *(p + i);
		++i;
	}
}

template<typename T>
MyVec<T>::MyVec()
{
}

template<typename T>
MyVec<T>::~MyVec()
{
	delete[] Vec;
}

template<typename T>
int MyVec<T>::size()
{
	return mySize;
}

template<typename T>
int MyVec<T>::capacity()
{
	return myCap;
}

template<typename T>
void MyVec<T>::print()
{
	if (Vec != nullptr)
	{
		for (int i = 0; i < mySize; ++i)
		{
			printf("%d\n", *(Vec + i));
		}
	}
	else if (Vec == nullptr)
	{
		printf("empty\n");
	}
}

template<typename T>
void MyVec<T>::popback()
{
	if (mySize == 0)
	{
		printf("empty\n");
		return;
	}

	*(Vec + (mySize - 1)) = NULL;
	--mySize;
}

template<typename T>
void MyVec<T>::pushback(T n)
{
	if (Vec == nullptr)
	{
		++myCap;
		Vec = new T[myCap]; // new T[0]과 같음, 문제가 있는 방법!!
							// 어셈블리로 넘어오는 데이터는 0byte!
		*(Vec+mySize) = n;
		++mySize;
		return;
	}
	if ((mySize + 1) > myCap)
	{
		myCap = (mySize + 1) * 1.2;
		T * Temp = Vec;
		Vec = new T[myCap];
		memcpy_s(Vec, sizeof(T)*mySize, Temp, sizeof(T)*mySize);
		*(Vec + mySize) = n;
		delete[] Temp; //소멸자가 안불렸는데 왜 지워지지 않는것
	}
	else
	{
		Vec[mySize] = n;
	}
	++mySize;
}

template<typename T>
void MyVec<T>::reserve(int n)
{
	if (myCap > n)
	{	
		return;
	}

	myCap = n; //예외처리 안되어있음.
	T * Temp = Vec;
	Vec = new T[myCap];
	memcpy_s(Vec, sizeof(T)*mySize, Temp, sizeof(T)*mySize);
	delete[] Temp;
}

template<typename T>
void MyVec<T>::sort()
{
	if (mySize == 0) return;

	T Temp = NULL;
	for (int i = 0; i < mySize; ++i)
	{
		for (int j = 0; j < (mySize - i - 1); ++j)
		{
			if (*(Vec + j) > *(Vec + j + 1))
			{
				Temp = *(Vec + j);
				*(Vec + j) = *(Vec + j + 1);$
				*(Vec + j + 1) = Temp;
			}
		}
	}
}

template<typename T>
void MyVec<T>::mergeSort()
{
	Mergesort(Vec, 0, mySize - 1);
}

const int ARRSIZE = 8;

void Merge(int Vec[], int start, int mid, int end)
{
	int TempArr[ARRSIZE] = {};
	int _start = start;
	int _mid = mid + 1;
	int _tempIndex = start;

	while (_start <= mid && _mid <= end)
	{
		if (Vec[_start] < Vec[_mid])
		{
			TempArr[_tempIndex] = Vec[_start];
			++_start;
		}
		else
		{
			TempArr[_tempIndex] = Vec[_mid];
			++_mid;
		}
		++_tempIndex;
	}

	if (_start > mid)
	{
		for (int index = _mid; index <= end; ++index)
		{
			TempArr[_tempIndex] = Vec[index];
			++_tempIndex;
		}
	}
	else
	{
		for (int index = _start; index <= mid; ++index)
		{
			TempArr[_tempIndex] = Vec[index];
			++_tempIndex;
		}
	}

	for (int index = start; index <= end; ++index)
	{
		Vec[index] = TempArr[index];
	}
}

void Mergesort(int Vec[], int start, int end)
{
	int mid = 0;
	if (start < end)
	{
		mid = (start + end) / 2;
		Mergesort(Vec, start, mid);
		Mergesort(Vec, mid + 1, end);
		Merge(Vec, start, mid, end);
	}
}

void BackMerge(int Vec[], int start, int mid, int end)
{
	int TempArr[ARRSIZE] = {};
	int _start = start;
	int _mid = mid + 1;
	int _tempIndex = start;

	while (_start <= mid && _mid <= end)
	{
		if (Vec[_start] > Vec[_mid])
		{
			TempArr[_tempIndex] = Vec[_start];
			++_start;
		}
		else
		{
			TempArr[_tempIndex] = Vec[_mid];
			++_mid;
		}
		++_tempIndex;
	}

	if (_start > mid)
	{
		for (int index = _mid; index <= end; ++index)
		{
			TempArr[_tempIndex] = Vec[index];
			++_tempIndex;
		}
	}
	else
	{
		for (int index = _start; index <= mid; ++index)
		{
			TempArr[_tempIndex] = Vec[index];
			++_tempIndex;
		}
	}

	for (int index = start; index <= end; ++index)
	{
		Vec[index] = TempArr[index];
	}
}

void MergeBacksort(int Vec[], int start, int end)
{
	int mid = 0;
	if (start < end)
	{
		mid = (start + end) / 2;
		MergeBacksort(Vec, start, mid);
		MergeBacksort(Vec, mid + 1, end);
		BackMerge(Vec, start, mid, end);
	}
}

int main()
{
	//MyVec<int> vec = { 2, 1, 6, 3, 7, 5, 4, 8 };

	int Vec[ARRSIZE] = { 2, 1, 6, 3, 7, 5, 4, 8 };

	MergeBacksort(Vec, 0, ARRSIZE - 1);

	for (int index = 0; index < ARRSIZE; ++index)
	{
		printf("%d ", Vec[index]);
	}
	std::cout << std::endl;

	Mergesort(Vec, 0, ARRSIZE - 1);

	for (int index = 0; index < ARRSIZE; ++index)
	{
		printf("%d ", Vec[index]);
	}
	std::cout << std::endl;

	//vec.print();
	//vec.mergeSort();
	//printf("\n");
	//vec.print();
	return 0;
}