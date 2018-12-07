#pragma once
#include"includes.h"

class Solution
{
public:
	vector<int> countBits(int num)
	{
		vector<int> res(num+1, 0);
		for (int i = 0; i < num+1; i++)
		{
			res[i] = res[i >> 1] + (i % 2);
		}
		return res;
	}
};