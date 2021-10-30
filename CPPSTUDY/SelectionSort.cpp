#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> vec)
{

	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int least = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] < vec[least])
			{
				least = j;
			}
		}
		if (i != least)
		{
			int temp = vec[i];
			vec[i] = vec[least];
			vec[least] = temp;
		}
	}
}

int main()
{
	return 0;
}