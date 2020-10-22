#pragma once
#include "includes.h"
class Solution
{
public:
	vector<string> buildArray(vector<int>& target, int n)
	{
		vector<string> res;
		int i = 1;
		for (int a : target)
		{
		begin:
			if (a == i++)
			{
				res.push_back("Push");
			}
			else
			{
				res.push_back("Push");
				res.push_back("Pop");
				goto begin;
			}
			if (i > n)
				break;
		}
		return res;
	}

	vector<string> buildArray2(vector<int>& target, int n)
	{
		vector<string> ans;
		int nextPush = 1;   // 下一个push的元素   
		for (int i = 0; i < target.size(); ++i) {
			while (nextPush<target[i]) {
				ans.push_back("Push");
				ans.push_back("Pop");
				nextPush++;
			}
			ans.push_back("Push");
			nextPush++;
		}
		return ans;
	}

	vector<string> buildArray3(vector<int>& target, int n)
	{
		vector<string> ans;
		int nextPush = 1;
		for (int i = 0; i < target.size(); ++i)
		{
			while (nextPush < target[i])
			{
				ans.push_back("Push");
				ans.push_back("Pop");
				nextPush++;
			}
			ans.push_back("Push");
			nextPush++;
		}
	}
};