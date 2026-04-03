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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftTreeHeight = getHeight(root->left);
        int rightTreeHeight = getHeight(root->right);

        if (abs(leftTreeHeight - rightTreeHeight) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }

    int getHeight(TreeNode* root){
        if (!root){
            return 0;
        }

        int leftTreeHeight = getHeight(root->left);
        int rightTreeHeight = getHeight(root->right);

        return 1 + max(leftTreeHeight, rightTreeHeight);
    }
};
