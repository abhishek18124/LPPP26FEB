/*

	Design an algorithm to perform insert operation in a BST.

*/

#include<iostream>
#include<queue>

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


void printInOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}
}

// time : O(height of the BST)
// space: O(height of the BST) due to fn call stack

TreeNode* insertInBST(TreeNode* root, int key) {

	// base case
	if (root == NULL) {
		return new TreeNode(key);
	}

	// recursive case

	if (key < root->val) {
		// insert the key in the leftSubtree, and since the leftSubtree is a BST we can ask our friend to do this for us
		root->left = insertInBST(root->left, key);
	} else {
		// key > root->val
		// insert the key in the rightSubtree, and since the rightSubtree is a BST we can ask our friend to do this for us
		root->right = insertInBST(root->right, key);
	}

	return root;

}

int main() {

	TreeNode* root = NULL;

	root = insertInBST(root, 10);

	root = insertInBST(root, 5);
	root = insertInBST(root, 3);
	root = insertInBST(root, 7);

	root = insertInBST(root, 15);
	root = insertInBST(root, 13);
	root = insertInBST(root, 17);

	root = insertInBST(root, 6);
	root = insertInBST(root, 14);

	printLevelOrder(root);

	cout << endl;

	printInOrder(root);

	cout << endl;

	return 0;
}