#pragma once
#include <stack>

#include "includes.h"

class Solution
{
public:
	vector<int> exclusiveTime(int n, vector<string>& logs)
	{
		vector<int> res(n, 0);
		stack<int> temp;
		int pretime = 0;
		for (string str : logs)
		{
			int pos1= str.find_first_of(":");
			int pos2 = str.find_last_of(":");
			int idx = stoi(str.substr(0, pos1));
			string type = str.substr(pos1 + 1, pos2-pos1-1);
			int time = stoi(str.substr(pos2 + 1));

			if (!temp.empty())
			{
				res[temp.top()] += time - pretime;
			}
			pretime = time;
			if (type == "start")
			{
				temp.push(idx);
			}
			else if(type == "end")
			{
				int tmp = temp.top();
				temp.pop();
				++res[tmp];
				pretime++;
			}
			else
			{
				;
			}
		}
		return res;
	}
};