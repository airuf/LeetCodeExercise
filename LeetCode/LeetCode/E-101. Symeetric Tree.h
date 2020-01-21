#pragma once
#include "includes.h"
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root = NULL)
			return true;
		return isSymmetric2(root->left, root->right);
	}

	bool isSymmetric2(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		if (root1 != NULL && root2 != NULL &&root1->val == root2->val)
			return isSymmetric2(root1->right, root2->left) && isSymmetric2(root1->left, root2->right);
		else
			return false;
	}
};