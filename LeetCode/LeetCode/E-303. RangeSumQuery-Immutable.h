#pragma once

#include "includes.h"

class NumArray
{
public:
	vector<int> num;
	NumArray(vector<int> nums)
	{
		num.resize(nums.size() + 1, 0);
		num[0] = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			num[i + 1] = nums[i] + num[i];
		}
	}

	int sumRange(int i, int j)
	{
		return num[j + 1] - num[i];
	}
};


/*
* You NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i, j);
*/