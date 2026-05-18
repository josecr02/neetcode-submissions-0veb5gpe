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
        // optimal solution, O(n).
        return dfs(root).first;
    }

    pair<int,int> dfs(TreeNode* root){
        // return [isBalanced, height];
        if (!root) return {1, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int h = 1 + max(left.second, right.second);
        bool balanced = (left.first == 1 && right.first == 1) && (abs(left.second - right.second) <= 1);
        return {balanced ? 1 : 0, h};
    }
};
