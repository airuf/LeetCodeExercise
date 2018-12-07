#include "includes.h"
#include "E-021. MergeTwoSortedLists.h"

ListNode *LinkedListCreatT(int i)
{
	ListNode *L;
	L = (ListNode *)malloc(sizeof(ListNode));   //申请头结点空间
	L->next = NULL;                  //初始化一个空链表
	ListNode *r;
	r = L;                          //r始终指向终端结点，开始时指向头结点 
	int x;                         //x为链表数据域中的数据
	L->val = i;
	while (i++<5) {
		ListNode *p;
		p = (ListNode *)malloc(sizeof(ListNode));   //申请新的结点 
		p->val = i;                     //结点数据域赋值 
		r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL 
		r = p;
		
	}
	r->next = NULL;

	return L;
}


int main()
{
	ListNode *a = LinkedListCreatT(2);
	ListNode *b = LinkedListCreatT(3);
	

	Solution X;
	
	ListNode *c = X.mergeTwoLists(a, b);

	system("pause");
	return 0;
}
