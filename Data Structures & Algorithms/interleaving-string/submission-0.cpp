class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // DP bottom up.
        //  for every possible pair of positions (i, j), whether it is possible to form
        // the suffix of s3 starting at position i + j using: s1[i:] and s2[j:].
        // dp[i][j] is true if s3[i + j:] can be formed using s1[i:] and s2[j:]
        // dp[len(s1)][len(s2)] = true because empty strings can form an empty string
        // If the next character of s1 matches s3[i + j] and dp[i + 1][j] is true, then set dp[i][j] = true
        // If the next character of s2 matches s3[i + j] and dp[i][j + 1] is true, then set dp[i][j] = true
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()){
            return false;
        }

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; --i){
            for (int j = n; j >= 0; --j){
                if (i < m &&  s1[i] == s3[i+j] && dp[i+1][j]){
                    dp[i][j] = true;
                }
                if (j < n && s2[j] == s3[i+j] && dp[i][j+1]){
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};
