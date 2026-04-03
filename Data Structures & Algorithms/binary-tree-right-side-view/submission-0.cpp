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
    vector<int> rightSideView(TreeNode* root) {
        // ok so we go as right as we can, if not, then left.
        // however we also need to go to the left to get the complete right view.
        // what I think: move in BFS order and only output right until empty, then left if remaining.
        // (i.e. last encountered node in that level).

        queue<TreeNode*> q;

        if (root == nullptr) return {};

        q.push(root);

        vector<int> res;

        while(!q.empty()){
            
            int nLevel = q.size();
            // iterate through that level
            for (int nodeIndex = 0; nodeIndex < nLevel; ++nodeIndex){
                TreeNode* node = q.front();
                q.pop();
                // add to queue children
                if (node->left){
                    q.push(node->left);
                } if (node->right){
                    q.push(node->right);
                }
                // we care about the last
                if (nodeIndex == nLevel - 1){
                    res.push_back(node->val); // rightmost node value
                }
            }

        }
        return res;
    }
};
