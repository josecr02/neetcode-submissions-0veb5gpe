class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // DP bottom up
        // ways to sum/subtract to equal target
        // At each position, we keep track of: all possible sums we can form, how many ways each sum can be formed
        // dp[i] stores how many ways each sum can be formed using the first i numbers
        // dp[0][0] = 1 since there is exactly one way to form sum 0 using no numbers
        // Add the current number → update dp[i + 1][sum + nums[i]]
        // Subtract the current number → update dp[i + 1][sum - nums[i]]
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i){
            for (auto &[sum,countOfWays] : dp[i]){
                dp[i+1][sum + nums[i]] += countOfWays;
                dp[i+1][sum - nums[i]] += countOfWays;
            }
        }

        return dp[n][target];
    }
};
