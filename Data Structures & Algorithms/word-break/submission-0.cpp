class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // return true if s can be segmented into a space-separated sequence of dictionary words.
        // DP bottom up.
        // end to start.
        // dp[i] means whether the substring s[i:] can be segmented

        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; --i){
            for (const auto& w : wordDict){
                if ((i + w.size() <= s.size() && s.substr(i, w.size()) == w)){
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]){
                    break;
                }
            }
        }

        return dp[0];
    }
};
