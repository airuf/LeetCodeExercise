#pragma once
#include "includes.h"

class NumArray {
private:
	vector<int> prefix;
public:
	NumArray(vector<int>& nums) 
	{
		int n = nums.size();
		prefix.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			prefix[i] = prefix[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j)
	{
		return prefix[j + 1] - prefix[i];
	}
};

