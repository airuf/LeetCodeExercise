#pragma once
#include "includes.h"

class Solution
{
public:
	bool stoneGame(vector<int>& piles)
	{
		int len = piles.size();
		vector<vector<int>> dp;
		dp.resize(len, vector<int>(len));
		for (int i = 0; i<len; i++)
			dp[i][i] = piles[i];
		for (int l = 2; l <= len; l++)
			for (int i = 0; i <= len - l; i++)
			{
				int j = i + l - 1;
				dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
			}
		return dp[0][len - 1]>0;
	}
};