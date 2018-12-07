#pragma once
#include "includes.h"

class Solution
{
public:
	int climbStairs(int n)
	{
		vector<int> s;
		s.push_back(1);
		s.push_back(2);
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		for (int i = 2; i < n; i++)
		{
			s.push_back(s[i - 1] + s[i - 2]);
		}
		return s[n - 1];
	}

	int climbStairs2(int n)
	{
		int dp[n + 1] = { 0 };
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};
