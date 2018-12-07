#pragma once
#include "includes.h"

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = nums[0];
		int max = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (sum > 0)
			{
				sum += nums[i];
			}
			else
			{
				sum = nums[i];
			}
			if (sum > max)
				max = sum;
		}
		return max;
	}

	int maxSubArray(vector<int>& nums)
	{
		int i, sum, ans = INT_MIN, n = nums.size();
		i = sum = 0;
		while (i < n)
		{
			sum += nums[i++];
			ans = max(ans, sum);
			if (sum < 0)
				sum = 0;
		}
		return ans;
	}
};
