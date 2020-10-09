#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isAnagram(std::string s, std::string t)
	{
		if (s.size() != t.size())
			return false;
		std::vector<char> s1;
		for (char c : s)
		{
			s1.push_back(c);
		}

		std::vector<char> s2;
		for (char c : t)
		{
			s2.push_back(c);
		}

		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());

		for (vector<char>::iterator l1 = s1.begin(), l2 = s2.begin(); l1 != s1.end(); ++l1,++l2)
		{
			if (*l1 != *l2)
			{
				return false;
			}
		}

		return true;
	}
};


