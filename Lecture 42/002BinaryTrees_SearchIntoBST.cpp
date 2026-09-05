/*

	Given a BST and a key, design an algorithm to search for the key in the BST.

	Output "true" is key is found otherwise output "false".

*/

#include<iostream>

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

// time : O(height of the BST)
// space: O(height of the BST) due to fn call stack

bool searchInBST(TreeNode* root, int key) {

	// base case
	if (root == NULL) {
		return false;
	}

	// recursive case

	// f(root, key) : it is fn that checks if the key exists in the given BST

	if (root->val == key) {
		return true;
	} else if (key < root->val) {
		// ask your friend to search for the key in the leftSubtree
		return searchInBST(root->left, key);
	} else {
		// key > root->val
		// ask your friend to search for the key in the rightSubtree
		return searchInBST(root->right, key);
	}

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	searchInBST(root, 7) ? cout << "true" << endl :
	                            cout << "false" << endl;

	return 0;
}


