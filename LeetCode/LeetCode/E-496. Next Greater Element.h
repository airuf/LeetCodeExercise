#pragma once
//��������û���ظ�Ԫ�ص����� nums1 �� nums2 ������nums1 �� nums2 ���Ӽ����ҵ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
//
//nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� - 1��

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
			while (i&&s[i - 1] < nums[j])	//��һ�����Ƿ��  �Ա��� ��
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




