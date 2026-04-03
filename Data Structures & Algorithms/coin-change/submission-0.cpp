class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // we have an array of size amount: 0..amount
        // we iterate through each possible amount, and for each, we go through all the coins
        // and we save the difference of using the coin.
        // we add 1 more coin in that case
        vector<int> dp(amount + 1, amount + 1); // amount + 1 so that we know when solution doesnt exist.
        dp[0] = 0; // 0 coins for 0 amount
        for (int i = 1; i <= amount; ++i){
            for (int j = 0; j < coins.size(); ++j){
                // check every coin that we can use
                if (coins[j] <=i){
                    // coin value is <= current amount target. we can use the coin
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};
