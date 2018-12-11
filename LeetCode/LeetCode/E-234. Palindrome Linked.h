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
	bool isPalindrome(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return true;
		
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *needReverser = slow->next;
		slow->next = NULL;
		needReverser = reverse(needReverser);

		ListNode *cur = head;
		while (cur && needReverser)
		{
			if (cur->val != needReverser->val)
			{
				return false;
			}
			cur = cur->next;
			needReverser = needReverser->next;
		}

		return true;
	}


	ListNode* reverse(ListNode *head)
	{
		ListNode *p1 = NULL;
		ListNode *p2 = head;
		ListNode *p3 = p2;

		while (p2)
		{
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
};