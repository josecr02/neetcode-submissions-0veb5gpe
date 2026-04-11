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

    int res = INT_MIN;

    int getMax(TreeNode* root){
        if (!root) return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + std::max(left, right);
        return std::max(0, path);
    }

    void dfs(TreeNode* root){
        if (!root) return;
        int left = getMax(root->left);
        int right = getMax(root->right);
        res = std::max(res, root->val + left + right);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        // not optimal DFS, best path is left + node + right
        dfs(root);
        return res;
        // O(n2) time and O(n) space, the time is bad because we are recomputing maxes in subtrees
    }
};
