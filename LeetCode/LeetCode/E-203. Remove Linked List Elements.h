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
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == NULL)
		{
			return NULL;
		}
		if (head->val == val && head->next == NULL)
		{
			return NULL;
		}
		if (head->val != val && head->next == NULL)
		{
			return head;
		}

		ListNode *p, *pre;
		ListNode *temp = new ListNode(0);
		temp->next = head;
		p = head;
		pre = temp;
		while (p)
		{
			if (p->val != val)
			{
				pre = p;
				p = p->next;
			}
			else
			{
				pre->next = p->next;
				p = pre->next;
			}
		}
		return temp->next;
	}


	ListNode* removeElements2(ListNode* head, int val)
	{
		ListNode* p = new ListNode(1);
		p->next = head;
		ListNode* re;
		re = p;
		if (head == NULL) return NULL;
		while (head)
		{
			if (head->val == val)
			{
				p->next = head->next;	
				head = head->next;
			}
			else
			{
				p = p->next;
				head = head->next;
			}
		}
		return re->next;
	}

	ListNode* removeElements3(ListNode* head, int val)
	{
		if (head == NULL)
			return NULL;
		ListNode *p = new ListNode(0);
		p->next = head;
		ListNode *temp;
		temp = p;
		while (head)
		{
			if (head->val == val)
			{
				p->next = head->next;
				head = head->next;
			}
			else
			{
				p = p->next;
				head = head->next;
			}
		}
		return temp->next;
	}
};