#pragma once
//非回文条件： 1、小于0  2、不是0而且最后一位是0，
//回文条件： 小于对比数时，进行取余数加到对比数上
//结束： 看是偶对称还是奇对称。返回结果
class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0))
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