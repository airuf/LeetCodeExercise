#pragma once
#include "includes.h"

class Solution
{
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		vector<int> sumCost(cost);
		int _length = cost.size();
		for (int i = 2; i < _length; i++)
		{
			sumCost[i] += min(sumCost[i - 1], sumCost[i - 2]);
		}
		return min(sumCost[cost.size()-1],sumCost[cost.size()-2]);
	}

	int minCostClimbingStairs2(vector<int>& cost)
	{
		int f1 = 0, f2 = 0;
		for (int i = cost.size() - 1; i >= 0; --i)
		{
			int f0 = cost[i] + min(f1, f2);
			f2 = f1;
			f1 = f0;
		}
		return min(f1, f2);
	}
};

