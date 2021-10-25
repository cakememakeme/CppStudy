#include "stdafx.h"
#include <iostream>

const int ARR = 10;

int partition(int a[], int start, int end)
{
//	int pivot = (start + end) / 2;						//ㅇㄹㄴ몰온머ㅏㅗㅓㅣㅏㄹㅇㄴ미ㅗㅓㅏㄹㅇㄹㅇㄴㅁ
	int pivot = a[(start + end) / 2];
	while (start <= end)
	{
		//while (a[start] < a[pivot]) ++start;			// ㅁㅇ너ㅣㄹㅇ널ㅇ노머ㅏㅗㄹㅇ머뇌ㅏㅓㄹㅇㄴ모ㅓㅏㄹㅇㅁ너ㅏㅗ
		//while (a[end] > a[pivot]) --end;				//ㅁ이널ㄹㅇ니ㅓㅏㄹㅇ미ㅏㅓ;ㄹㄴ미ㅏ얼ㅇㅁ니ㅏㅓㄹㅇㅁ너ㅏㄹㅇㄴ머ㅣㅏ
		while (a[start] < pivot) ++start;
		while (a[end] > pivot) --end;
		if (start <= end)
		{
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start++;
			end--;
		}
	}
	return start;
}

void quicksort(int a[], int start, int end)
{
	int	part = partition(a, start, end);
	if (start < end)
	{
		quicksort(a, start, part - 1);
		quicksort(a, part, end);
	}

}

int Partition(int a[], int start, int end)
{
	int pivot = a[(start + end) / 2];
 	while (start <= end)
	{
		while (a[start] < pivot) start++;
		while (a[end] > pivot) end--;
		if (start <= end)
		{
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start++;
			end--;
		}
	}

	return start;
}


void QuickSort(int a[], int start, int end)
{
	int part = Partition(a, start, end);
	if (start < part - 1)
		QuickSort(a, start, part - 1);
	if (end > part)
		QuickSort(a, part, end);
	return;
}

int main()
{
//	int a[ARR] = { 5, 4, 7, 9, 6, 3, 2, 8, 1, 0};
	int a[ARR] = { 5, 4, 3, 0, 1, 9, 2, 6, 7, 8 };
//	int a[ARR] = { 1, 7, 4, 6, 2, 9, 3};
	for (int i = 0; i < ARR; ++i)
	{
		printf("%d ", a[i]);
	}
	quicksort(a, 0, ARR - 1);
	std::cout << std::endl;
	for (int i = 0; i < ARR; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}