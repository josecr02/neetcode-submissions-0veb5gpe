class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // DP bottom up
        // 0/1 subset sum problem.
        // Let dp[i][j] mean: using the first i numbers, can we form sum j?
        // Skip it → the possibility stays dp[i-1][j]
        // Take it (only if nums[i-1] <= j) → check dp[i-1][j - nums[i-1]]
        int sum = 0;
        for (int num : nums){
            sum += num;
        }
        if (sum % 2 != 0){
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= target; ++j){
                if (nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};
