#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParityII(vector<int>& A)
	{
		int temp = 0;
		for (int i = 0, j = 1; i < A.size(); i=i+2)
		{
			if (A[i] % 2 != 0)
			{
				for (; j < A.size(); j = j + 2)
				{
					if (A[j] % 2 != 1)
					{
						temp = A[j];
						A[j] = A[i];
						A[i] = temp;
						break;
					}
				}
			}
		}
		return A;
	}
};