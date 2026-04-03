class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // we need to select all combinations that sum up to target
        // no duplicate combinations
        // sort + backtracking
        // there are 2^n combinations, so worst case is O(2^n x n).
        // O(n) space.
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int i, vector<int>& cur, int total){
        if (total == target){
            res.push_back(cur);
            return;
        }

        if (total > target || i == candidates.size()){
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target, i + 1, cur, total + candidates[i]);
        cur.pop_back();

        // advance index while the next number is the same, to avoid duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            ++i;
        }
        dfs(candidates, target, i + 1, cur, total);
    }
};
