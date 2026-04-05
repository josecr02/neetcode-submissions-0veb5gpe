class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // we want combinations of unlimited coins to sum up to amount
        // dp[i][a] represents the number of ways to form amount a using coins from index i onward
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, 0));

        for (int i = 0 ; i <= n; ++i){
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; --i){
            for (int a = 0; a <= amount; ++a){
                // If we can take the coint! (amoun is still bigger)
                if (a >= coins[i]){
                    // skip the coin
                    dp[i][a] = dp[i+1][a];
                    // take the coint too
                    dp[i][a] += dp[i][a - coins[i]];
                }
                
            }
        }
        // O(na) time and space
        return dp[0][amount];
    }
};
