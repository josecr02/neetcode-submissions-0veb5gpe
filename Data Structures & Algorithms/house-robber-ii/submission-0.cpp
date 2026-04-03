class Solution {
public:
    int rob(vector<int>& nums) {
        // houses are circular.
        // bottom-up DP.
        // we cant rob both frst and last, so we consider 1 to n-1 and 0 to n -2 .
        if (nums.size() == 1) return nums[0];
        int rob1 = helper(vector<int>(nums.begin() + 1, nums.end()));
        int rob2 = helper(vector<int>(nums.begin(), nums.end() - 1));
        return max(rob1, rob2);
    }

    int helper(vector<int> nums){
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size()); // maximum money up to house i.
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size()-1];
    }
};
