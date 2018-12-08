#include "includes.h"
#include "E-203. RemoveLinkedListElements.h"


void InitLinkedList(ListNode *lst, const vector<int> *a)
{
	ListNode *cp1 = lst;
	vector<int> _data = *a;
	ListNode *p;
	cp1->val = _data[0];
	for (int _dataLen = _data.size(), i = 1; i < _dataLen; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		cp1->next = p;
		cp1 = cp1->next;
		p->val = _data[i];
		p->next = NULL;
	}
}

int main()
{
	struct ListNode l1(0);
	//vector<int> a{ 1,2,6,3,4,5,6 };
	vector<int> a{ 1,1};
	InitLinkedList(&l1,&a);
	struct ListNode l2(NULL);
	Solution S;
	S.removeElements(&l2, 2);

	system("pause");
	return 0;
}
