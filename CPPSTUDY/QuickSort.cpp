#include <iostream>
#include <vector>

void QuickSort(std::vector<int> vec, int left, int right)
{
	int idx = Partition(vec, left, right);
	if (left < idx - 1)
	{
		QuickSort(vec, left, idx - 1);
	}
	if (idx < right)
	{
		QuickSort(vec, idx, right);
	}
}

int Partition(std::vector<int> vec, int left, int right)
{
	int pivot = vec[(left + right) / 2];
	while (left <= right)
	{
		while (vec[left] < pivot) ++left;
		while (vec[right] > pivot) --right;

		if (left <= right)
		{
			int temp = vec[left];
			vec[left] = vec[right];
			vec[right] = temp;
			++left;
			--right;
		}
	}
}

int main()
{

	return 0;
}