/*

given the pre-order traversal of a binary tree, design a recursive algorithm
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any
	  two TreeNodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 70 -1 -1 -1 -1 40 -1 60 -1 80 -1 -1 90 -1 -1
          Output : 6

          Input  : 10 20 -1 -1 30 40 60 80 -1 -1 -1 -1 50 -1 70 -1 90 -1 -1
          Output : 6

*/

#include<iostream>
#include<cmath>
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


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int findHeight(TreeNode* root) {

	// base case

	if (root == NULL) {
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively find the height of the leftSubtree
	int leftHgt = findHeight(root->left);

	// 2. recursively find the height of the rightSubtree
	int rightHgt = findHeight(root->right);

	return 1 + max(leftHgt, rightHgt);

}


// time : O(n)

class Pair {
public:
	int hgt;
	int dia;
};

Pair dfs(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.dia = 0;
		p.hgt = -1;
		return p;
	}

	// recursive case

	// f(root) : find the diameter of the given tree

	// 1. ask your friend to find the diameter and height of the leftSubtree

	Pair left = dfs(root->left);

	// 2. ask your friend to find the diameter and height of the rightSubtree

	Pair right = dfs(root->right);

	// 3. find the length of the longest path b/w two nodes that goes via the root node

	int longestLenViaRoot = left.hgt + right.hgt + 2;

	p.hgt = 1 + max(left.hgt, right.hgt);
	p.dia = max({left.dia, right.dia, longestLenViaRoot});

	return p;

}

int main() {

	TreeNode* root = buildTree();

	Pair p = dfs(root);

	cout << p.dia << endl;

	return 0;
}