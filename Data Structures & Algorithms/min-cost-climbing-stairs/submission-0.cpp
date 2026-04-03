class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // DP 1D bottom-up
        // dp[i] is min cost to reach step i
        // dp[0] = 0, dp[1] = 0 (you can start at step 0 or 1 for free)
        int n = cost.size();
        vector<int> dp(n+1);
        
        for (int i = 2; i <= n; ++i){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};
