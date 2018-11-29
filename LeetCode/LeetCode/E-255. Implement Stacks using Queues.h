#pragma once

#include <queue>

#include "includes.h"

class MyStack {
public:
	queue<int> temp, tarQueue;

	/* Initialize your data structure here. */
	MyStack()
	{

	}

	/* Push element x onto stack. */
	void push(int x)
	{
		while (!tarQueue.empty())
		{
			temp.push(tarQueue.front());
			tarQueue.pop();
		}
		tarQueue.push(x);
		while (!temp.empty())
		{
			tarQueue.push(temp.front());
			temp.pop();
		}
	}

	/* Removes the element on top of the stack and returns that elements */
	int pop()
	{
		int x = tarQueue.front();
		tarQueue.pop();
		return x;
	}

	/* Get the top element */
	int top()
	{
		return tarQueue.front();
	}

	/* Returns whether the stack is empty. */
	bool empty()
	{
		return tarQueue.empty();
	}
};

