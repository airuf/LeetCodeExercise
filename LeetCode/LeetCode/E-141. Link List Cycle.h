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
	bool hasCycle(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
		{
			return false;
		}
		ListNode *fast = head, *slow = head;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}

	bool hasCycle2(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
		{
			return false;
		}
		if (head->next == head)
		{
			return true;
		}
		ListNode *l = head->next;
		bool isCycle = hasCycle2(l);

		return isCycle;
	}
};