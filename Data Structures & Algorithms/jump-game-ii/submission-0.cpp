class Solution {
public:
    int jump(vector<int>& nums) {
        // dp[i] represents the minimum number of jumps needed to reach the last index from index i
        // so the result is dp[0]
        int n = nums.size();
        vector<int> dp(n, 1000);
        dp[n-1] = 0;

        for (int i = n - 2; i >= 0; --i){
            int end = min(n - 1, i + nums[i]); // last index to visit
            for (int j = i + 1; j <= end; ++j){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[0];

    }
};
