#pragma once
#include <stack>

#include "includes.h"

class Solution
{
public:
	bool backspaceCompare(string S, string T)
	{
		stack<char> s1, s2;
		for (char c : S)
		{
			if (c == '#')
			{
				if (!s1.empty())
				{
					s1.pop();
				}
			}
			else
			{
				s1.push(c);
			}
		}
		for (char c : T)
		{
			if (c == '#')
			{
				if (!s2.empty())
				{
					s2.pop();
				}
			}
			else
			{
				s2.push(c);
			}
		}

		return s1 == s2 ? 1 : 0;
	}

	bool backspaceCompare2(string S, string T)
	{
		vector<char> s1, s2;
		for (char c : S)
		{
			if (c == '#')
			{
				if (!s1.empty())
				{
					s1.pop_back();
				}
			}
			else
			{
				s1.push_back(c);
			}
		}
		for (char c : T)
		{
			if (c == '#')
			{
				if (!s2.empty())
				{
					s2.pop_back();
				}
			}
			else
			{
				s2.push_back(c);
			}
		}

		return s1 == s2 ? 1 : 0;
	}
};

