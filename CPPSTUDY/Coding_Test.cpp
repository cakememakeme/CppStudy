#include "stdafx.h"
#include <iostream>

int main()
{
	int XGeneration = 0;
	int YGeneration = 0;

	int finalCell = 0;
	int X_numOfCell = 1;
	int Y_numOfCell = 1;
	int Energy = 0;

	std::cin >> XGeneration >> YGeneration >> finalCell;
	
	--XGeneration;
	--YGeneration;
	if (XGeneration > YGeneration)
	{
		int swapTemp = YGeneration;
		YGeneration = XGeneration;
		XGeneration = swapTemp;
	}
	
	while ((X_numOfCell + Y_numOfCell) != finalCell)
	{
		if (XGeneration <= YGeneration)
		{
			int isSquare = 1;

			for (isSquare ; isSquare <= X_numOfCell ; isSquare *= 2)

			if (X_numOfCell == isSquare)
			{
				++XGeneration;
			}

			Energy += XGeneration;
			++X_numOfCell;
		}
		else
		{
			int isSquare = 1;

			for (isSquare; isSquare <= Y_numOfCell; isSquare *= 2)

			if (Y_numOfCell == isSquare)
				{
					++YGeneration;
				}
			Energy += YGeneration;
			++Y_numOfCell;
		}
	}
	
	std::cout << Energy;
	return 0;
}