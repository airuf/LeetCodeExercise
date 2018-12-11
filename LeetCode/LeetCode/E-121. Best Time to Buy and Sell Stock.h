#pragma once
#include "includes.h"

class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
		{
			return 0;
		}
		int profit = 0;
		int buy = prices[0];
		for (int i = 0; i < prices.size(); i++)
		{
			buy = min(buy, prices[i]);
			profit = max(profit, prices[i] - buy);
		}
		return profit;
	}
};