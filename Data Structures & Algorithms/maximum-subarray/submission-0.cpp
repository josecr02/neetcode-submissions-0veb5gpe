class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DP bottom up
        // dp[i][1] = maximum subarray sum that must start at index i
        // dp[i][0] = maximum subarray sum that starts at index i or later
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        dp[n-1][1] = dp[n-1][0] = nums[n-1];
        for (int i = n - 2; i >= 0; --i){
            dp[i][1] = max(nums[i], nums[i] + dp[i+1][1]);
            dp[i][0] = max(dp[i][1], dp[i+1][0]);
        }

        return dp[0][0];
    }
};
