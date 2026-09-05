/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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


bool dfs(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// f(root) : check if the given tree is a bst or not

	// 1. ask your friend to check if the leftSubtree is a bst

	bool leftIsBst = dfs(root->left);

	// 2. ask your friend to check if the rightSubtree is a bst

	bool rightIsBst = dfs(root->right);

	// 3. check if the bst prop. works at the root

	bool isBstPropWorkingAtRoot = root->val > findMaximum(root->left) and
	                              root->val < findMinimum(root->right) ? true : false;


	return leftIsBst and rightIsBst and isBstPropWorkingAtRoot;

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	dfs(root) ? cout << "bst" << endl : cout << "not a bst" << endl;

	return 0;
}