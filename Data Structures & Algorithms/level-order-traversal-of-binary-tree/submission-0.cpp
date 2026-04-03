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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> curLevel;
        vector<vector<int>> res;
        if (root == nullptr) return res;

        curLevel.push(root);
        while (!curLevel.empty()){
            vector<int> currentLevel_vector;
            int elementsInLevel = curLevel.size();
            for (int el = 0; el < elementsInLevel; ++el){
                // remove all the elements in this level
                TreeNode* newNode = curLevel.front();
                curLevel.pop();
                currentLevel_vector.push_back(newNode->val);
                // and we add the children to the end of the stack
                if (newNode->left){
                    curLevel.push(newNode->left);
                }
                if (newNode->right){
                    curLevel.push(newNode->right);
                }
            }
            res.push_back(currentLevel_vector);
        }
        return res;
    }
};
