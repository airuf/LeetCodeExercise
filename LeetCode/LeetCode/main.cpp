#include "includes.h"
#include "E-021. MergeTwoSortedLists.h"

ListNode *LinkedListCreatT(int i)
{
	ListNode *L;
	L = (ListNode *)malloc(sizeof(ListNode));   //����ͷ���ռ�
	L->next = NULL;                  //��ʼ��һ��������
	ListNode *r;
	r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ��� 
	int x;                         //xΪ�����������е�����
	L->val = i;
	while (i++<5) {
		ListNode *p;
		p = (ListNode *)malloc(sizeof(ListNode));   //�����µĽ�� 
		p->val = i;                     //���������ֵ 
		r->next = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL 
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
