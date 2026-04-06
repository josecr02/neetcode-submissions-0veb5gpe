class Solution {
public:
    int numDecodings(string s) {
        // same but more space O(1)\
        // dp1 → ways to decode from i + 1
        // dp2 → ways to decode from i + 2
        int dp1 = 1; // dp[s.size()]
        int dp2 = 0;
        int ways = 0;
        for (int i = s.size() - 1; i >= 0; --i){
            
            if (s[i] == '0'){
                ways = 0;                
            } else {
                ways = dp1;
                if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) {
                    ways += dp2;
                }                
            }
            dp2 = dp1;
            dp1 = ways;
            ways = 0;
        }

        return dp1;
    }
};
