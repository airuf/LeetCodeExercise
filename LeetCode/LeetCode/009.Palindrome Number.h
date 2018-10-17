#pragma once
class Solution
{
public:
	bool IsPalindrome(int x)
	{
		if (x < 0 && (x % 10 == 0 && x != 0))
		{
			return false;
		}
			
		int reverteNumber = 0;
		while (x > reverteNumber)
		{
			reverteNumber = reverteNumber * 10 + x % 10;
			x /= 10;
		}
		return x == reverteNumber || x == reverteNumber / 10;
	}
};