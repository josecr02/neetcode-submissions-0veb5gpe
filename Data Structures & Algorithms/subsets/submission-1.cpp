class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        generate(nums, subset, 0, res);
        return res;
    }

    void generate(const vector<int>& nums, vector<int>& currentSubset, int i, vector<vector<int>>& res){
        if (i >= nums.size()){
            res.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(nums[i]);
        generate(nums, currentSubset, i+1, res);
        currentSubset.pop_back();
        generate(nums, currentSubset, i+1,res);
    }
};
