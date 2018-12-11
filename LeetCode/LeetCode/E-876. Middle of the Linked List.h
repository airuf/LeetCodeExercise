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
	ListNode* middleNode(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* pa = head;
		ListNode* pb = head;
		while (pa->next != NULL)
		{
			pa = pa->next;
			pb = pb->next;
			if (pa->next != NULL)
			{
				pa = pa->next;
			}
		}
		return pb;
	}

	ListNode* middleNode2(ListNode* head)
	{
		if (head == NULL)
		{
			return head;
		}
		int count = 0;
		ListNode* node = head;
		vector<ListNode*> saveNode;
		while (node)
		{
			count++;
			saveNode.push_back(node);
			node = node->next;
		}
		return saveNode[count / 2];
	}
};
