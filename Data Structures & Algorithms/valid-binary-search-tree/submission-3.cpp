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
    bool isValidBST(TreeNode* root) {
        return checkValid(root, INT_MIN, INT_MAX);
    }

private:
    bool checkValid(TreeNode* root, int left, int right){
        if (!root) return true;
        if (left < root->val && right > root->val){
            return checkValid(root->left, left, root->val) && checkValid(root->right, root->val, right);
        } else {
            return false;
        }
    }
};
