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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // iterative dfs with stack
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});

        while (!s.empty()){
            auto [n1, n2] = s.top();
            s.pop();

            if (!n1 && !n2) continue;
            if (!n2 || !n1) return false;
            if (n1->val != n2->val) return false;
            s.push({n1->right, n2->right});
            s.push({n1->left, n2->left});
        }

        return true;
    }
};
