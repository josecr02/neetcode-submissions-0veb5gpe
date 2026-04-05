class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // optimized dp with just O(a) space
        // each row depends only on the row below it (skipping the coin) and the current row (using the coin)
        // dp[a] represents the number of ways to form amount a using coins processed so far
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = coins.size() - 1; i >=0; --i){
            vector<int> nextDP(amount + 1, 0);
            nextDP[0] = 1;

            for (int a = 1; a <= amount; ++a){
                nextDP[a] = dp[a];
                if (a >= coins[i]){
                    nextDP[a] += nextDP[a - coins[i]];
                }
            }
            dp = nextDP;
        }

        return dp[amount];
    }
};
