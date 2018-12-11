#pragma once

#include "includes.h"

class Solution 
{
public:
	// Transform S into T.
	// For example, S = "abba", T = "^#a#b#b#a#$".
	// ^ and $ signs are sentinels appended to each end to avoid bounds checking
	string  preProcess(string s)
	{
		int n = s.length();
		if (n == 0)
			return "^$";
		string ret = "^";
		for (int i = 0; i < n; i++)
		{
			ret += "#" + s.substr(i, 1);
		}
		ret += "#$";
		return ret;
	}
	
		//我们假设p[1~i - 1]已经求好了，现在要求p[i]：
		//假设当前能达到的最右边为R，对应的中点为pos，j是i的对称点。
		//1.当i＜R时

		//由于L~R是回文，所以p[i] = p[j]（i的最长回文和j的最长回文相同）。

		//这种情况是另一种：j的最长回文跳出L了。那么i的最长回文就不一定是j的最长回文了，但蓝色的肯定还是满足的。

		//综上所述，p[i] = min(p[2 * pos - i], R - i)。
		//2.当i >= R时
		//由于后面是未知的，于是只能暴力处理了。
		//-------------------- -
		//原文：https ://blog.csdn.net/zzkksunboy/article/details/72600679?utm_source=copy 

	string longestPalindrome(string s)
	{
		string T = preProcess(s);
		int n = T.length();
		int *P = new int[n];
		int C = 0, R = 0;
		int m = 0;
		for (int i = 1; i < n - 1; i++) 
		{
			int i_mirror = 2 * C - i; // equals to i' =C - (i-C)
			P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

			//Attempt to expand palindrome centered at i 
			while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
				P[i]++;

			//IF palindrome centered at i expand past R,\
			 adjust center based on expanded palindrome.
			if (i + P[i] > R)
			{
				C = i;
				R = i + P[i];
			}
		}

		//Find the maximum element in P.
		int maxLen = 0;
		int centerIndex = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (P[i] > maxLen)
			{
				maxLen = P[i];
				centerIndex = i;
			}
		}
		delete[] P;

		return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
	}
};


