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
        // same with BFS
        if (!root) return true;


        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, INT_MIN, INT_MAX));
        while (!q.empty()){
            auto [node, left, right] = q.front();
            q.pop();
            // now i check its withing its range
            if (!(node->val > left && node->val < right)) return false;
            if (node->left){
                q.push(make_tuple(node->left, left, node->val));
            }
            if (node->right){
                q.push(make_tuple(node->right, node->val, right));
            }
        }

        return true;

    }
};
