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
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal
        // left -> node -> right. this gives sorted order. then kth.
        // we do it with a DFS. we count as we go.
        vector<int> res(2, 0);
        res[0] = k; // we need to count k times
        dfs(root, res);
        return res[1];
    }

    void dfs(TreeNode* node, vector<int>& res){
        if (!node) return;
        dfs(node->left, res);
        res[0]--; // count
        if (res[0] == 0){
            // this was the kth element
            res[1] = node->val;
            return;
        }
        dfs(node->right, res);
    }
};
