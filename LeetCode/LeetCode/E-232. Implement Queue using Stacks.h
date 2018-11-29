#pragma once
#include <stack>

#include "includes.h"

class MyQueue {
public:
	stack<int> temp, tarStack;

	/* Initialize your data structure here. */
	MyQueue() 
	{

	}
	
	/** Push element x to the back of queue */
	void push(int x)
	{
		while (!tarStack.empty())
		{
			temp.push(tarStack.top());
			tarStack.pop();
		}
		tarStack.push(x);
		while (!temp.empty())
		{
			tarStack.push(temp.top());
			temp.pop();
		}
	}

	/** Remeves the element from in front of queue and returns that element */
	int pop() 
	{
		int a = tarStack.top();
		tarStack.pop();
		return a;
	}

	/** Get the front element */
	int peek()
	{
		return tarStack.top();
	}

	/* Retruns whether the queue is empty */
	bool empty()
	{
		return tarStack.empty();
	}

};



