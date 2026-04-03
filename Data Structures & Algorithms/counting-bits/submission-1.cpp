class Solution {
public:
    vector<int> countBits(int n) {
        // DP 
        // number of 1 is 1 (for the highest power of two) + number of set bits in the remainder
        vector<int> dp(n+1);
        int offset = 1;

        for (int i = 1; i <= n; ++i){
            if (offset * 2 == i){
                offset = i;
            }
            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};
