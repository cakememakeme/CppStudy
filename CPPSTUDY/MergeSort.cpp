#include <iostream>
#include <vector>

void MergeSort(std::vector<int> vec)
{
	std::vector<int> helper(vec.size(), 0);
	MergeSort(vec, helper, 0, vec.size() - 1);
}

void MergeSort(std::vector<int> vec, std::vector<int> helper, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(vec, helper, low, mid);
		MergeSort(vec, helper, mid + 1, high);
		Merge(vec, helper, low, mid, high);
	}
}

void Merge(std::vector<int> vec, std::vector<int> helper, int low, int mid, int high)
{
	for(int i = low; i <= high; ++i)
	{
		helper[i] = vec[i];
	}

	int helperLeft = low;
	int helperRight = mid + 1;
	int curr = low;

	while (helperLeft <= mid && helperRight <= high)
	{
		if (helper[helperLeft] <= helper[helperRight])
		{
			vec[curr] = helper[helperLeft];
			++helperLeft;
		}
		else
		{
			vec[curr] = helper[helperRight];
			++helperRight;
		}
		++curr;
	}

	int remaining = mid - helperLeft;
	for (int i = 0; i <= remaining; ++i)
	{
		vec[curr + i] = helper[helperLeft + i];
	}
}

int main()
{
	
	return 0;
}