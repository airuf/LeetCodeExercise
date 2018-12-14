#pragma once
#include "includes.h"

#if 1
struct ListNode
{
	int val;
	ListNode *prev;
	ListNode *next;
	ListNode(int x):val(x), prev(NULL), next(NULL){}
};
class MyLinkedList
{
public:
	int val;
	ListNode* head;
	//Initialize your data sturcture here;
	MyLinkedList()
	{
		head = NULL;
	}

	//get the value of the index-th node in the linked list. If the index is invalid, return -1;
	int get(int index)
	{
		if (head == NULL)
		{
			return -1;
		}
		ListNode *temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				return -1;
			}
		}
		return temp->val;
	}

	//Add a node of value val before the first elemnet of the linked list. After the insertion, the new node will be the first node of the linked list;
	void addAtHead(int val)
	{
		ListNode *a = (ListNode*)malloc(sizeof(ListNode));
		a->val = val;
		a->prev = NULL;
		if (!head)
		{
			a->next = NULL;
			head = a;
			return;
		}
		a->next = head;
		head->prev = a;
		head = a;
	}

	//Append a node of value val to the last element of the linked list;
	void addAtTail(int val)
	{
		ListNode *a = (ListNode*)malloc(sizeof(ListNode));
		ListNode *t = head;
		a->val = val;
		a->next = NULL;
		if (!head)
		{
			a->next = NULL;
			head = a;
			return;
		}
		while (t->next)
		{
			t = t->next;
		}
		a->prev = t;
		t->next = a;
	}

	//Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be append to the end of linked list. If index is greater than the length the node will not be inserted.
	void addAtIndex(int index, int val)
	{
		ListNode *p = head;
		ListNode *q = p;
		ListNode *a = (ListNode*)malloc(sizeof(ListNode));
		if (index == 0)
		{
			a->val = val;
			a->prev = NULL;
			a->next = NULL;
			head = a;
			return;
		}
		while (index)
		{
			q = p;
			if (p == NULL)
			{
				return;
			}
			p = p->next;
			index--;
		}
		
		a->val = val;
		a->prev = q;
		
		q->next = a;
		if (p == NULL)
		{
			a->next = NULL;
			return;
		}
		a->next = p;
		p->prev = a;
	}

	//Delete the index-th node in the linked list, if the index is vaild.
	void deleteAtIndex(int index)
	{
		ListNode *p = head;
		if (head == NULL)
		{
			return;
		}

		while (index)
		{
			p = p->next;
			if (p == NULL)
			{
				return;
			}
			index--;
		}
		if (p == NULL)
		{
			return;
		}
		if (p->next == NULL)
		{
			p->prev->next = NULL;
		}
		else
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		delete p;
	}
};

#else

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		LinkedList = 0;
	}
	ListNode *LinkedList;
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		int i = 0;
		ListNode *head = LinkedList;
		while (head&&i<index) {
			head = head->next;
			i++;
		}
		if (head&&i == index) return head->val;
		else return -1;

	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode *head = (ListNode *)malloc(sizeof(ListNode));
		head->next = LinkedList;
		head->val = val;
		LinkedList = head;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode *head = LinkedList;
		ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
		tmp->next = 0;
		tmp->val = val;
		if (!head) {
			LinkedList = tmp;
			return;
		}
		while (head->next) {
			head = head->next;
		}
		head->next = tmp;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		int i = 0;
		ListNode *head = LinkedList;
		if (!head&&index == 0) {
			ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->val = val;
			tmp->next = 0;
			LinkedList = tmp;
			return;
		}
		while (head&&i<index - 1) {
			head = head->next;
			i++;
		}
		if (head&&head->next == 0) {
			ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->val = val;
			tmp->next = 0;
			head->next = tmp;
		}
		else if (i == index - 1 && head&&head->next) {
			ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
			tmp->val = val;
			tmp->next = head->next;
			head->next = tmp;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		ListNode *head = LinkedList;
		int i = 0;
		while (head&&i<index - 1) {
			head = head->next;
			i++;
		}
		if (head == 0) return;
		if (head->next == 0 && index == 0) {//只有一个节点的情况
			LinkedList = 0;
			return;
		}
		if (head->next) {
			ListNode *tmp = head->next;
			head->next = tmp->next;
			free(tmp);
		}
	}
};

#endif