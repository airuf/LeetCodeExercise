#include "includes.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *hn = NULL, *t, *p, *q;
		int x, y, carry = 0, sum;
		//ergodic list
		for (p = l1, q = l2; p || q;)
		{
			//if NULL ,value = 0;
			x = p != NULL ? p->val : 0;
			y = q != NULL ? q->val : 0;

			if (!hn)
			{
				hn = t = (ListNode*)malloc(sizeof(ListNode));
			}
			else
			{
				t = t->next = (ListNode*)malloc(sizeof(ListNode));
			}
			t->next = NULL;
			t->val = (carry + x + y) % 10;

			carry = x + y + carry > 9 ? 1 : 0;

			if (p)
				p = p->next;
			if (q)
				q = q->next;
		}

		if (carry == 1)
		{
			t = t->next = (ListNode*)malloc(sizeof(ListNode));
			t->next = NULL;
			t->val = 1;
		}
		return hn;
	}
};





