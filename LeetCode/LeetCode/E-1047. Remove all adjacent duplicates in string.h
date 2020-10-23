#pragma once
#include "includes.h"
#include <string>
#include <stack>
#include <algorithm>

class Solution
{
public:
	string removeDuplicates(string S)
	{
		if (S.length() == 0 && S.length() == 1)
		{
			return S;
		}
		stack<char> res;
		for (char data : S)
		{
			if (!res.empty())
			{
				if (data != res.top())
				{
					res.push(data);
				}
				else
				{
					res.pop();
				}
			}
			else
			{
				res.push(data);
			}
		}
		string resS;
		while (!res.empty())
		{
			resS.push_back(res.top());
			res.pop();
		}
		reverse(resS.begin(), resS.end());
		return resS;
	}

	string removeDuplicates2(string S) {
		int idx = -1;
		for (int i = 0; i < S.size(); ++i) {
			if (idx == -1 || S[idx] != S[i])
				S[++idx] = S[i];
			else if (S[idx] == S[i])
				idx--;
		}
		return S.substr(0, idx + 1);
	}
};
