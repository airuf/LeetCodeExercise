#pragma once

#include "includes.h"


class Solution
{
public:
	string toLowerCase(string str)
	{
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}

	string toLowerCase2(string str)
	{
		int n = str.size();
		for (int i = 0; i<n; i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
		}
		return str;
	}
};