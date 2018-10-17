#include "includes.h"

class Solution
{
public:
	double findMedianSortedArrays(vector<int> A, vector<int> B)
	{
		int m = A.size();
		int n = B.size();
		if (m > n)
		{
			vector<int> temp = A;
			A = B;
			B = temp;
			int tmp = m;
			m = n;
			n = tmp;
		}
		int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
		while (iMin <= iMax)
		{
			int i = (iMin + iMax) / 2;
			int j = halfLen - i;
			if (i < iMax && B[j - 1] > A[i])
			{
				iMin = iMin + 1;
			}
			else if (i > iMin && A[i - 1] > B[j])
			{
				iMax = iMax - 1;
			}
			else
			{
				int maxLeft = 0;
				if (i == 0)
				{
					maxLeft = B[j - 1];
				}
				else if (j == 0)
				{
					maxLeft = A[i - 1];
				}
				else
				{
					maxLeft = max(A[i - 1], B[j - 1]);
				}
				if ((m + n) % 2 == 1)
				{
					return maxLeft;
				}

				int minRight = 0;
				if (i == m)
				{
					minRight = B[j];
				}
				else if (j == n)
				{
					minRight = A[i];
				}
				else
				{
					minRight = min(B[j], A[i]); //why chose one , Are we dont know which is right ?
				}
				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
	}
};

//This is have some 
class Solution2 {
public:
	double findMedianSortedArrays(vector<int> A, vector<int> B)
	{
		int m = A.size(), n = B.size();
		int s = m + n;
		if (s & 0x01)
		{
			return findKth(A, B, 0, 0, m, n, s / 2 + 1);
		}
		else
		{
			double a = findKth(A, B, 0, 0, m, n, s / 2);
			double b = findKth(A, B, 0, 0, m, n, s / 2 + 1);
			return (a + b) / 2;
		}
	}
private:
	double findKth(vector<int> A, vector<int> B, int start1, int start2, int m, int n, int k)
	{
		if (m > n)
		{
			return findKth(B, A, start2, start1, n, m, k);
		}
		if (m = 0)
		{
			return B[start2 + k - 1];
		}
		if (k == 1)
		{
			return min(A[start1], B[start2]);
		}
		int  x = min(k / 2, n), y = k - x;
		if (A[start1 + x - 1] < B[start2 + y - 1])
		{
			return findKth(A, B, start1 + x, start2, m - x, n, k - x);
		}
		else
		{
			if (A[start1 + x - 1] > B[start2 + y - 1])
			{
				return findKth(A, B, start1, start2 + y, m, n - y, k - y);
			}
			else
			{
				return A[start1 + x - 1];
			}
		}
	}
};

