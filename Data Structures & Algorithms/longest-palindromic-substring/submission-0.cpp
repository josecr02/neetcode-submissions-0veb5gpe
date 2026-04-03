class Solution {
public:
    string longestPalindrome(string s) {
        // dp solution, O(n2)
        // dp[i][j] = true if the substring s[i..j] is a palindrome.
        // Special small cases: if the length is 1, 2, or 3 (j - i <= 2), then matching ends 
        // is enough because the middle is empty or a single char.
        // bottom-up.
        int resIdx = 0, resLen = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i){
            for (int j = i; j < n; ++j){
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if (resLen < (j - i + 1)){
                        resIdx = i;
                        resLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);

    }
};
