#pragma once
//给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 - 1。

#include "includes.h"
#include <unordered_map>
#include <stack>
class Solution {
public:
	//O(n2)
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
	{
		vector<int> A;
		for (int findNum : findNums)
		{
			bool B = false;
			for (int i = 0; i < nums.size(); i++)
			{
				if (findNum == nums[i])
				{
					B = true;
				}
				if (B && findNum < nums[i])
				{
					A.push_back(nums[i]);
					B = false;
					break;
				}
			}
			if(B)
			{
				A.push_back(-1);
			}
			return A;
		}
	}
	//412 1342
	//O(2n)
	vector<int> nextGreaterElement2(vector<int> &findNums, vector<int> &nums)
	{
		int n_len = nums.size();
		vector<int> res, s(n_len);
		unordered_map<int, int> next;
		for (int i = 0, j = 0; j < n_len; s[i++] = nums[j++])
		{
			while (i&&s[i - 1] < nums[j])	//下一个数是否比  对比数 大
				next[s[--i]] = nums[j];
		}
		for (int n : findNums) res.push_back(next.count(n) ? next[n] : -1);
		return res;
	}


	//use stack
	vector<int> nextGreaterElement3(vector<int>& findNums, vector<int>&nums)
	{
		stack<int> s;
		unordered_map<int, int> m;
		for (int n : nums) 
		{
			while (s.size() && s.top() < n)
			{
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector<int> ans;
		for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
		return ans; 
	}
};




