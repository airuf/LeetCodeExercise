#pragma once
#include "includes.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode *q)
	{
		if (p == NULL && q == NULL)
			return true;
		if (p != NULL && q != NULL && p == q)
			return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
		else 
			return false;
	}

};