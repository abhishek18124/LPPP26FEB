/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* root, long long lb, long long ub) {

        if (root == NULL) {
            return true;
        }

        // f(root) : check if the given tree is a bst or not

        return root->val > lb and root->val < ub and
               dfs(root->left, lb, root->val) and
               dfs(root->right, root->val, ub);

    }

    bool isValidBST(TreeNode* root) {
        long long lb = INT_MIN - 1ll;
        long long ub = INT_MAX + 1ll;
        return dfs(root, lb, ub);
    }
};