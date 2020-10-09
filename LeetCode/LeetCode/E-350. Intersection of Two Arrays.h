#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
//untreate
class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		//str1 is longer	
		std::map<int, int> record;
		if (nums1.size() < nums2.size()) {
			return intersect(nums2, nums1);
		}

		for (int i = 0; i < nums1.size(); ++i)
		{
			++record[nums1[i]];
		}

		vector<int> res;
		for (int i = 0; i < nums2.size(); ++i)
		{
			if (record.count(nums2[i]))
			{
				res.push_back(nums2[i]);
				--record[nums2[i]];
				if (record[nums2[i]] == 0)
				{
					record.erase(nums2[i]);
				}
			}
		}
		
		return res;
	}
};

