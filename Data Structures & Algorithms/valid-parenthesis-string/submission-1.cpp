class Solution {
public:
    bool checkValidString(string s) {
       int n = s.size();
       vector<vector<bool>> dp(n + 1, vector<bool>(n+1, false));
       dp[n][0] = true;

       for (int i = n - 1; i >= 0; --i){
        for (int open = 0; open < n; ++open){
            bool res = false;
            if (s[i] == '*'){
                if (dp[i+1][open+1] || (open > 0 && dp[i+1][open-1]) || (dp[i+1][open])){
                    res = true;
                }
            } else {
                if (s[i] == '('){
                    res |= dp[i+1][open + 1];
                } else {
                    res |= dp[i+1][open-1];
                }
            }
            dp[i][open] = res;
        }
       }

       return dp[0][0];
    }
};
