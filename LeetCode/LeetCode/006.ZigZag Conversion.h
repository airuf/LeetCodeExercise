#pragma once
#include "includes.h"

class Solution 
{
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
		{
			return s;
		}
		
		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s)
		{
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1)
			{
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) 
			ret += row;					//一次复制一个字符串
		return ret;
		
	}
};


class solution2
{
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;

		string ret;
		int n = s.size();
		int cyclenLen = 2 * numRows - 2;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j + i < n; j += cyclenLen)
			{
				ret += s[j + i];
				if (i != 0 &&i != numRows - 1 && j + cyclenLen - i < n)
				{
					ret += s[j + cyclenLen - i];
				}
			}
		}
		return ret;
	}
};