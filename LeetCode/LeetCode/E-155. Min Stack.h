#pragma once
#include <stack>

#include "includes.h"


class MinStack {
public:
	
	MinStack() {
		min = INT_MAX;
	}

	void push(int x)
	{
		if (x <= min)
		{
			s1.push(min);
			min = x;
		}
		s1.push(x);
	}

	void pop()
	{
		if (s1.top() == min)
		{
			s1.pop();
			min = s1.top();
			s1.pop();
		}
		else
		{
			s1.pop();
		}
	}

	int top()
	{
		return s1.top();
	}

	int getMin()
	{
		return min;
	}

private:
	int min;
	stack<int> s1;
};