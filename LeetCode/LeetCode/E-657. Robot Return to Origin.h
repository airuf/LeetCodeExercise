#pragma once

#include "includes.h"
#include <stack>

class Solution
{
public:
	void TestData()
	{
		string data = "UD";
		std::cout << judgeCircle(data) << std::endl;
		data = "LDRRLRUULR";
		std::cout << judgeCircle(data) << std::endl;

	}

	bool judgeCircle(string moves)
	{
		int horizontal = 0, vertical = 0;
		for (char c : moves)
		{
			if (c == 'L')
			{
				horizontal++;
			}
			else if (c == 'R')
			{
				horizontal--;
			}
			else if (c == 'U')
			{
				vertical++;
			}
			else if (c == 'D')
			{
				vertical--;
			}
		}
		return (horizontal==0&&vertical == 0);
	}

};

