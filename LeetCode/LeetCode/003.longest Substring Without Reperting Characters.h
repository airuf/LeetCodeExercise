#include "includes.h"
#include "unordered_map"
class Solution 
{
public:
	/*
	left	��¼�����λ��
	m[s[i]]	��¼��һ����ĸ��λ��
	res		�������
	*/
	int lengthOfLongestSubstring(string s)
	{
		int res = 0, left = 0, i = 0, n = s.size();
		unordered_map<char, int> m;
		for (int i = 0; i < n; ++i)
		{
			left = max(left, m[s[i]]);
			m[s[i]] = i + 1;
			res = max(res, i - left + 1);
		}
		return res;
	}
};



