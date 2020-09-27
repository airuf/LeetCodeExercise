#pragma once
#include "includes.h"

class solution {
public:
	int minPathSum(vector<vector<int>> & grid)
	{
		if (grid[0].size() == 0 || grid.size() == 0)
			return 0;
		int rows = grid.size(), columns = grid[0].size();
		int i = 0 , j = 0;
		auto tempData= vector < vector <int> >(rows, vector<int>(columns));
		tempData[0][0] = grid[0][0];
		for (i = 1; i < rows; i++)
		{
			tempData[i][0] = tempData[i - 1][0] + grid[i][0];
		}
		for(j= 1;j < columns; j++)
		{
			tempData[0][j] = tempData[0][j - 1] + grid[0][j];
		}
		
		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < columns; j++)
			{
				tempData[i][j] = min(tempData[i - 1][j], tempData[i][j - 1]) + grid[i][j];
			}
		}
		return tempData[rows - 1][columns - 1];
	}
};