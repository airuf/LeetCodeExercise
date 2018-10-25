#pragma once
#include "includes.h"

//	https://www.cnblogs.com/willaty/p/8134672.html

class Solution
{
public:
	bool cmatch(char s, char p)
	{
		return p == '*' || p == '.' || s == p;
	}


	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		bool* arr = new bool[n + 1]();
		arr[0] = 1;

		for (int i = 2; i <= n; ++i)
			if (p[i - 1] == '*' && arr[i - 2] == true) arr[i] = true;

		int j2 = arr[0];
		int j1 = arr[1];
		int sa = arr[2];

		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j <= n; ++j)
				if (j == 0) {
					j2 = arr[0];
					arr[0] = false;
				}
				else if (j == 1) {
					j1 = arr[1];
					arr[1] = i == 1 && cmatch(s[0], p[0]);
				}
				else {
					sa = arr[j];
					if (p[j - 1] == '*')
						arr[j] = cmatch(s[i - 1], p[j - 2]) && (arr[j] || arr[j - 1] || j1 || j2 || arr[j - 2]) ? true : arr[j - 2];
					else
						arr[j] = cmatch(s[i - 1], p[j - 1]) ? j1 : false;
					j2 = j1;
					j1 = sa;
				}
		}
		return arr[n];
	}
};


