#pragma once
#include "includes.h"
#include <string>

class Solution
{
public:
	string removeDuplicates(string S)
	{
		string res;
		int i, j = 0;
		for (; i < S.length()-1; i++)
		{
			while (S[i] == S[++j])
			if (S[j] == S[i - 1] && i > 0)
			{
				i = i - 1;
			}
			else
			{
				res.push_back(S[i]);
			}
			i = j;
		}
		return res;
	}
};
