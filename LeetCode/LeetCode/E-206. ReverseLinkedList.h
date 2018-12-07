#pragma once
#include "includes.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* res = head;
		if (res == NULL || res->next == NULL)
		{
			return res;
		}

		ListNode* tmp = res->next, *tmp2;
		
		res->next = NULL;
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			tmp->next = res;
			res = tmp;
			tmp = tmp2;
		}
		return res;
	}
};