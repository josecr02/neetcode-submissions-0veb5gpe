class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res{};
        vector<int> cur;
        vector<int> pick(nums.size(), 0);
        generate(nums, cur, res, pick);
        return res;
    }


    void generate(const vector<int>& nums, vector<int>& currentPermutation, vector<vector<int>>& res, vector<int>& pick){
        if (nums.size() == currentPermutation.size()){
            res.push_back(currentPermutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i){
            if (!pick[i]){
                pick[i] = true;
                currentPermutation.push_back(nums[i]);
                generate(nums, currentPermutation, res, pick);
                pick[i] = false;
                currentPermutation.pop_back();
            }

        }
    }
};
