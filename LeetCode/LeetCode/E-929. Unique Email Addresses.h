#pragma once

#include "includes.h"


class Solution
{
public:
	void TestData()
	{
		vector<string> b{ "abc@abc", "abc.2@abc", "ab.c@abc", "ab+c@abc", "abc+asdfa@abc", "ab.c+dc@abc" };

		std::cout << numUniqueEmails(b) <<std::endl;
	}


	int numUniqueEmails(vector<string>& emails)
	{
		vector<std::string> temp;
		for (int i = 0; i < emails.size(); i++)
		{
			while (emails[i].find(".") < emails[i].find("@"))
			{
				emails[i].erase(emails[i].find("."),1);
			}
			while (emails[i].find("+") < emails[i].find("@"))
			{
				emails[i].erase(emails[i].find("+"), emails[i].find("@")-emails[i].find("+"));
			}
		}
		
		for (int i = 0; i < emails.size(); i++)
		{
			for (int j = i+1; j < emails.size(); )
			{
				if (emails[i] == emails[j])
				{
					emails.erase(emails.begin()+j);
				}
				else
				{
					j++;
				}
			}
		}
		return emails.size();
	}

	int numUniqueEmails2(vector<string>& emails) 
	{
		unordered_set<string> set;
		for (auto &s : emails) {
			unsigned int p, a;
			while (p = s.find('.'), a = s.find('@'), p != std::string::npos && p < a)
				s.erase(p, 1);
			if (p = s.find('+'), a = s.find('@'), p != std::string::npos && p < a)
				s.erase(p, a - p);
			set.insert(s);
		}
		return set.size();
	}

};