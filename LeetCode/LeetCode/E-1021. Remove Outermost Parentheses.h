#pragma once
#include "includes.h"

class Solution
{
public:
	string removeOuterParentheses(string S) {
		int cnt = 0;
		string res;
		for (auto c : S) {
			if (c == '(') {
				cnt++;
				if (cnt == 1) continue;
			}
			else cnt--;
			if (cnt != 0)res.push_back(c);
		}
		return res;
	}
};