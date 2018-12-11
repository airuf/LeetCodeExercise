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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head==NULL || head->next == NULL)
		{
			return head;
		}
		ListNode *a = head;
		while (a->next && a)
		{
			if (a->val == a->next->val)
				a->next = a->next->next;
			else
			{
				a = a->next;
			}
		}
		return head;
	}
};