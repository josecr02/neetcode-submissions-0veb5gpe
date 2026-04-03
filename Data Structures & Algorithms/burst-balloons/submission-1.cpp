class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // first we do brute force and then bottom-up.
        // we tru every possible balloon as last.
        // since we try every possible choice, this is 2^n choices,
        // times n since we iterate through the array during each choice.
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dfs(nums);
    }

    int dfs(vector<int>& nums){
        if (nums.size() == 2) return 0;

        int maxCoins = 0;
        for (int i = 1; i < nums.size() - 1; ++i){
            int coins = nums[i - 1] * nums[i] * nums[i + 1];
            vector<int> newNums = nums;
            newNums.erase(newNums.begin() + i);
            coins += dfs(newNums);
            maxCoins = max(maxCoins, coins);
        }
        return maxCoins;
    }
};
