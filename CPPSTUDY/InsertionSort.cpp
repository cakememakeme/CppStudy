#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> vec)
{
	for(int i = 1; i < vec.size(); ++i)
	{
		int key = vec[i];
		int j = 0;
		for (j = i - 1; j >= 0 && vec[j] > key; --j)
		{
			vec[j + 1] = vec[j];
		}
		vec[j + 1] = key;
	}
}

int main()
{
	return 0;
}