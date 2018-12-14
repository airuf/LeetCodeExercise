#include "includes.h"
#include <algorithm>


using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> backup(nums);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			cout << " " << i <<":" << nums[i];
		}
		cout << endl;
		vector<int>::iterator i1 = nums.begin(), i2 = nums.end()-1;
		while ((*i1 + *i2) != target)
		{
			while ((*i1 + *i2)<target)
				i1++;
			while ((*i1 + *i2) > target)
				i2--;
		}
		vector<int> res;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (backup[i] == *i1 || backup[i] == *i2)
				res.push_back(i);
		}
		return res;
	}
};



int Test001(void)
{
	vector<int> nums = { 3, 2,2,3,4,5,44,3544,22 };
	Solution answer;
	vector<int> data = answer.twoSum(nums, 9);

	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i];
	}
	cout << endl;
	//printf("[%d, %d]\n", data[0], data[1]);
	system("pause");
	return 0;
}
