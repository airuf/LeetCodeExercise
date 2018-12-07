#pragma once
#include "includes.h"

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *head = new ListNode(0);
		ListNode *res = head;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				head->next = l2;
				l2 = l2->next;
				head = head->next;
			}
			else
			{
				head->next = l1;
				l1 = l1->next;
				head = head->next;
			}
		}
		while (l1)
		{
			head->next = l1;
			l1 = l1->next;
			head = head->next;
		}
		while (l2)
		{
			head->next = l2;
			l2 = l2->next;
			head = head->next;
		}
		
		return res->next;
	}


	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
	{
		ListNode* l3 = new ListNode(0);
		ListNode *a1 = l1, *a2 = l2;
		ListNode *a3 = l3;
		while (a1&&a2) {            //依次比较两个链表中数的大小
			if (a1->val <= a2->val) {
				a3->next = a1;
				a1 = a1->next;
				a3 = a3->next;
			}
			else {
				a3->next = a2;
				a2 = a2->next;
				a3 = a3->next;
			}
		}
		while (a1) {        //若l1链表有剩余，则全部放到最后
			a3->next = a1;
			a1 = a1->next;
			a3 = a3->next;
		}
		while (a2) {        //若l2链表有剩余，则全部放到最后
			a3->next = a2;
			a2 = a2->next;
			a3 = a3->next;
		}
		return l3->next;

	}
};