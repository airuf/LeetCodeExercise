#pragma once
#include "includes.h"

class Solution
{
public:
	void TestData()
	{
		vector<char> data = { 'h','e','l','l','o' };
		reverseString(data);
		for (char c : data)
		{
			std::cout << c;
		}
		std::cout << endl;

		data = { 'H','a','n','n','a','h' };
		reverseString(data);
		for (char c : data)
		{
			std::cout << c;
		}
		std::cout << endl;
	}

	void reverseString(vector<char>& s)
	{
		char c;
		int num = s.size();
		for (int i = 0; i < num/2; i++)
		{
			c = s[num - i -1];
			s[num - i-1] = s[i];
			s[i] = c;
		}
	}

	string reverseString(string s) {
		std::reverse(s.begin(), s.end());
		return std::move(s);
	}
};

