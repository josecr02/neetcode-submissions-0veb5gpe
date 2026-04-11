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

    int dfs(TreeNode* root, int& res){
        if (!root) return 0;

        int left = dfs(root->left, res);
        int leftMax = max(left, 0); // ignore negative paths
        int right = dfs(root->right, res);
        int rightMax = max(right, 0);

        res = max(res, root->val + leftMax + rightMax); // best path through node
        return root->val + max(leftMax, rightMax); // bext extendable downward path
    }
    int maxPathSum(TreeNode* root) {
        // optimal DFS, every node can have: Max Downward Path starting at this node and Max Path Through This Node
        // visit each node ONCE, O(n) time and space
        int res = root->val;
        dfs(root, res);
        return res;
        
    }
};
