#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
	std::vector<int> intersection(std::vector<int>&nums1, std::vector<int>&nums2)
	{
		std::vector<int> dataPool;
		for (int i = 0; i < nums1.size(); i++)
		{
			int bAlreadyexisted = 0;
			for (int m : dataPool)
			{
				if (m == nums1[i])
				{
					bAlreadyexisted = 1;
					break;
				}
			}
			if (bAlreadyexisted == 0)
			{
				for (int j = 0; j < nums2.size(); j++)
				{
					if (nums1[i] == nums2[j])
					{
						dataPool.push_back(nums1[i]);
						break;
					}
				}
			}

		}
		return dataPool;
	}

	std::vector<int> q_intersection(std::vector<int>&nums1, std::vector<int>&nums2)
	{
		std::unordered_set<int> record;
		for (int i = 0; i < nums1.size(); ++i)
		{
			record.insert(nums1[i]);
		}
		std::unordered_set< int > result;
		for (int i = 0; i < nums2.size(); ++i)
		{
			if (record.find(nums2[i]) != record.end())
				result.insert(nums2[i]);
		}
		std::vector<int> ret;
		for (std::unordered_set<int>::iterator i = result.begin(); i != result.end(); ++i)
		{
			ret.push_back(*i);
		}
		return ret;
	}
};