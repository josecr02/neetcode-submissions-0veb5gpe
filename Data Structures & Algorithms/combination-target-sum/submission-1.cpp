class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> comb{};
        vector<vector<int>> res;
        generate(nums, 0, target, comb, res);
        return res;
    }

    void generate(const vector<int>& nums, int i, int target, vector<int>& currentCombination, vector<vector<int>>& res){
        if (target == 0){
            res.push_back(currentCombination);
            return;
        }
        if (target < 0 || i >= nums.size()){
            return;
        }
        currentCombination.push_back(nums[i]);
        generate(nums, i, target - nums[i], currentCombination, res); // we can use i mu;tiple times
        currentCombination.pop_back();
        generate(nums, i + 1, target, currentCombination, res);
    }
};
