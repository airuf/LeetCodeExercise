#pragma once
#include "includes.h"


class Solution
{
public:
	void TestData()
	{
		vector<string> data{ "gin", "zen", "gig", "msg" };
		std::cout << uniqueMoreseRepresentations(data) << std::endl;
	}

	int uniqueMoreseRepresentations(vector<string>& words)
	{
		const vector<string> ch2MorseLib = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		unordered_set<string> res;
		for (string s : words)
		{
			string part;
			for (char c : s)
			{
				part += ch2MorseLib[c-'a'];
			}
			res.insert(part);
		}
		return res.size();
	}
};