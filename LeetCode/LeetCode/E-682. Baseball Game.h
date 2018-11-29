#pragma once
#include "includes.h"
#include <stack>
#include <numeric>


class Solution {
public:
	int calPoints(vector<string>& ops)
	{
		stack<int> res;
		for (int n= 0 ; n<ops.size(); n++) 
		{
			if (ops[n] == "+")
			{
				int m = res.top();
				res.pop();
				int n = res.top();
				res.push(m);
				res.push(m + n);
			}
			else if (ops[n] == "D")
			{
				int m = res.top() * 2;
				res.push(m);
			}
			else if (ops[n] == "C")
			{
				res.pop();
			}
			else
			{
				res.push(stoi(ops[n]));
			}
		}
		int sum = 0;
		while(!res.empty())
		{
			sum += res.top();
			res.pop();
		}
		return sum;
	}

	int calPoint(vector<string>& ops)
	{
		vector<int> res;
		int length = ops.size();
		for (int n = 0; n < length; n++)
		{
			if (ops[n] == "+")
			{
				res.push_back(res[res.size() - 1] + res[res.size() - 2]);
			}
			else if (ops[n] == "D")
			{
				res.push_back(res[res.size() - 1] * 2);
			}
			else if (ops[n] == "C")
			{
				res.pop_back();
			}
			else
			{
				res.push_back(stoi(ops[n]));
			}
		}
		int sum = 0;
		for (int i = 0; i < res.size(); i++)
		{
			sum += res[i];
		}
		return sum;
	}
};

//执行用时0ms 的算法。。。。
class Solution2 {
public:
	int calPoints(vector<string>& ops) {
		int size = ops.size();
		vector<int> rlt;
		for (const auto& o : ops) {
			if (o == "C") rlt.pop_back();
			else if (o == "D") rlt.push_back(rlt.back() * 2);
			else if (o == "+") rlt.push_back(rlt.back() + rlt[rlt.size() - 2]);
			else rlt.push_back(stoi(o));
		}
		return accumulate(rlt.begin(), rlt.end(), 0);
	}
};

static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();