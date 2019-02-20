#pragma once
#include "includes.h"

class Solution
{
public:

	void TestData()
	{
		string data{ "Let's take LeetCode contest" };
		std::cout << reverseWords(data) << std::endl;
	}


	string reverseWords(string s)
	{
		string temp;
		string res;
		for (char c : s)
		{
			if (c == ' ')
			{
				std::reverse(temp.begin(), temp.end());
				temp += ' ';
				res = res + temp;
				temp.clear();
			}
			else
			{
				temp += c;
			}
		}
		std::reverse(temp.begin(), temp.end());
		res = res + ' ' + temp;
		temp.clear();
		return res;
	}

	string reverseWords2(string s)
	{
		auto p = s.begin();
		auto q = s.begin();
		while (p < s.end())
		{
			while (*p != ' ' && p != s.end())
			{
				p++;
			}
			std::reverse(p, q);
			p++;
			q = p;
		}
	}
};
