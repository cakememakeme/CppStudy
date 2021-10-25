#include "stdafx.h"
#include <iostream>
#include <chrono>

int fibo(int a)
{
	int count = 2;
	int x, y;
	x = y = 1;
	while (1)
	{
		x = x + y;
		count++;
		if (count >= a) break;
		y = x + y;
		count++;
		if (count >= a) break;
	}
	if (count % 2 == 1) return x;
	if (count % 2 == 0) return y;
}

int arrMax(int _arr[])
{
	int max = _arr[0];
	for (int i = 0; i < 8; ++i)
	{
		int temp = 0;
		for (int j = i; j < 8; ++j)
		{
			temp += _arr[j];
		}
		if (temp > max) max = temp;
	}
	return max;
}

int F(int n) {
	int prev = 1;
	int next = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum = prev + next;
		sum %= 1234567;
		prev = next;
		next = sum;
	}

	return sum;
}

int fibonachi(int n, int arr[], int& Cref)
{

	if (n == 1 || n == 2)
		return 1;
	arr[Cref] = n;
	Cref++;
	/*for (int i = 0; i < Cref; ++i)
	{
		if(arr[i] == )
	}*/
	return fibonachi(n - 1, arr, Cref) + fibonachi(n - 2, arr, Cref);
}

int fibArr[100000] = {0};
int recurfib(int n)
{
	if (n == 1 || n == 2) return 1;
	if (fibArr[n] != 0) return fibArr[n];
	return fibArr[n] = recurfib(n - 2) + recurfib(n - 1);
}
int main()
{
	int bb = 0;
	int arr[100] = {};
	int count = 0;
	int &Cref = count;
	std::cout << F(7);
	return 0;
	//bb = fibonachi(7, arr, Cref);

	/*for (int a = 0; a < 10; ++a)
	{
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 100000; ++i)
		{
			bb = fibo(30);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << duration << "ns total, average : " << duration / 100000 << "ns. " << std::endl;
		printf("%d\n", bb);
	}

	for (int a = 0; a < 10; ++a)
	{
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 100000; ++i)
		{
			bb = fibonachi(30);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << duration << "ns total, average : " << duration / 100000 << "ns. " << std::endl;
		printf("%d\n", bb);
	}*/
	//int max = 0;
	//max = arrMax(arr);
	//printf("%d\n", max);

}