class Solution {
public:
    int numDecodings(string s) {
        // we ask How many ways can I decode starting at index i?
        // bottom-up
        // we just depend on next or next 2 positions for dp (1 - 26)
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1; // 1 way for empty
        for (int i = n-1; i >= 0; --i){
            if (s[i] == '0'){
                dp[i] = 0; // invalid start!
            } else {
                dp[i] = dp[i+1]; // use 1 digit
                if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) {
                    dp[i] += dp[i+2]; // consume 2 digits, and then add the rest
                }
            }
        }

        return dp[0];
    }
};
