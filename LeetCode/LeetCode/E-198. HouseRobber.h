#pragma once
#include "includes.h"

class Solution {
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		vector<int> moneys(nums);

		if (nums.size() > 2)
			moneys[2] += moneys[0];

		for (int i = 3; i < nums.size(); i++)
		{
			moneys[i] += max(moneys[i - 2], moneys[i - 3]);
		}
		return max(moneys[moneys.size() - 1], moneys[moneys.size() - 2]);
	}
};

