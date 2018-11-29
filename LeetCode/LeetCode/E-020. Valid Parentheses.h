#pragma once
#include <stack>

#include "includes.h"

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> s1;
		for (char c : s)
		{
			if (c == '(' | c == '[' | c== '{')
			{
				s1.push(c);
			}
			else
			{
				if (s1.empty())
				{
					return false;
				}
				else if (c == ')')
				{
					if (s1.top() == '(')
						s1.pop();
					else
						return false;
				}
				else if (c == ']')
				{
					if (s1.top() == '[')
						s1.pop();
					else
						return false;
				}
				else
				{
					if (s1.top() == '{')
						s1.pop();
					else
						return false;
				}
			}
		}
		return s1.empty();
	}
};