class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; ++i){
            newNums[i+1] = nums[i]; // copy over
        }

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        // dp[l][r] is the maximum number of coins we can get by bursting baloons from l to r.
        for (int l = n; l >= 1; --l){ // l goes n to 1
            for (int r = l; r <= n; ++r){ // r goes from l to n
                for (int i = l; i <= r; ++i){ // we try each ballon in [l,r] as last balloon to burst
                    int coins = newNums[l - 1] * newNums[i] * newNums[r + 1];
                    // if we burst i last, then the previous ballon is l - 1, and next is r + 1
                    coins += dp[l][i - 1] + dp[i + 1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[1][n];

        // time is O(n3) and space is O(n2)
    }
};
