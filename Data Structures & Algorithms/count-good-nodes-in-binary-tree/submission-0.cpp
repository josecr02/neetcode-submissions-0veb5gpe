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
    int goodNodes(TreeNode* root) {
        // so in other words, node x needs to be the max value along the path to the root (inclusive).
        // we can do a BFS, and remember the max 
        // better option is to just do dfs. but we do bfs

        int res = 0;
        queue<pair<TreeNode*, int>> q; // we keep a queue of nodes, each with the max value seen so far.

        if (root == nullptr) return 0;
        q.push({root, -101});

        while (!q.empty()){
            int elementsInLevel = q.size();

            for (int el = 0; el < elementsInLevel; ++el){
                auto [node, maxVal] = q.front();
                q.pop();
                // add children in bfs, accounting for max
                if (node->left){
                    q.push({node->left, max(maxVal, node->val)});
                } if (node->right){
                    q.push({node->right, max(maxVal, node->val)});
                }
                if (node->val >= maxVal){
                    // good node seen
                    ++res;
                }
            }
        }
        return res;
    }
};
