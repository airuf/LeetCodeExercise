#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;
		if (candidates.size() == 0 || target < 0)
			return res;
	}

	int recursionNum(vector<int> copy, int target)
	{
		for (int i = 0; i < copy.size(); i++)
		{
			if (copy[i] == target)
				break;
		}
	}
};