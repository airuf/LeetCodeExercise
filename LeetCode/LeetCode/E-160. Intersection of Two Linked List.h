#pragma once
#include "includes.h"
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int countA = 0, countB = 0, maxLen = 0;
		if (headA == NULL || headB == NULL)
		{
			return NULL;
		}
		ListNode *A = headA, *B = headB;
		while (A)
		{
			if (A != NULL)
			{
				countA++;
				A = A->next;
			}
		}
		while (B)
		{
			if (B != NULL)
			{
				countB++;
				B = B->next;
			}
		}
		if (A != B)
			return NULL;
		A = headA;
		B = headB;
		if (countA > countB)
		{
			for (int i = 0; i < countA - countB; i++)
			{
				A = A->next;
			}
		}
		else
		{
			for (int i = 0; i < countB - countA; i++)
			{
				B = B->next;
			}
		}
		while (A != NULL)
		{
			if (A == B)
			{
				return A;
			}
			A = A->next;
			B = B->next;
		}
		return NULL;
	}
};