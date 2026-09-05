/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}


int findMaximum(TreeNode* root) {


	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

class Triple {

public:

	bool isBst;
	int minVal;
	int maxVal;

};


Triple dfs(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {
		t.isBst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	// f(root) : check if the given tree is a bst or not

	// 1. ask your friend to check if the leftSubtree is a bst

	Triple left = dfs(root->left);

	// 2. ask your friend to check if the rightSubtree is a bst

	Triple right = dfs(root->right);

	// 3. check if the bst prop. works at the root

	bool isBstPropWorkingAtRoot = root->val > left.maxVal and
	                              root->val < right.minVal ? true : false;


	t.isBst = left.isBst and right.isBst and isBstPropWorkingAtRoot;
	t.minVal = min({left.minVal, right.minVal, root->val});
	t.maxVal = max({left.maxVal, right.maxVal, root->val});

	return t;

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(6);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	Triple t = dfs(root);

	t.isBst ? cout << "bst" << endl : cout << "not a bst" << endl;

	return 0;
}