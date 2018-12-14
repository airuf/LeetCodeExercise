#pragma once
#include "includes.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution
{
public:
	ListNode* swapPairs(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode *A = head, *B = A, *C = NULL, *res = A->next;
		while(A&&A->next!=NULL)
		{
			B = A->next;
			if (C != NULL)
			{
				C->next = B;
			}
			A->next = B->next;
			B->next = A;
			C = A;
			A = A->next;
		}
		return res;
	}
};
