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
	
		//���Ǽ���p[1~i - 1]�Ѿ�����ˣ�����Ҫ��p[i]��
		//���赱ǰ�ܴﵽ�����ұ�ΪR����Ӧ���е�Ϊpos��j��i�ĶԳƵ㡣
		//1.��i��Rʱ

		//����L~R�ǻ��ģ�����p[i] = p[j]��i������ĺ�j���������ͬ����

		//�����������һ�֣�j�����������L�ˡ���ôi������ľͲ�һ����j��������ˣ�����ɫ�Ŀ϶���������ġ�

		//����������p[i] = min(p[2 * pos - i], R - i)��
		//2.��i >= Rʱ
		//���ں�����δ֪�ģ�����ֻ�ܱ��������ˡ�
		//-------------------- -
		//ԭ�ģ�https ://blog.csdn.net/zzkksunboy/article/details/72600679?utm_source=copy 

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


