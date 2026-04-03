class Solution {
    vector<vector<bool>> dp;
public:
// OPTIMAL! Backtrack DP to precompute palindrome substrings.
// dp[i][j] that tells whether s[i..j] is a palindrome.
// Then use backtracking just like before, but instead of checking palindromes on the fly, we directly look up dp[i][j].
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n, vector<bool>(n, false));
        // l = lengthToAdd
        for (int l = 1; l <= n; ++l){
            for (int i = 0; i <= n - l; ++i){
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] && 
                                    (i + 1 > (i + l - 2) ||
                                    dp[i+1][i+l-2])); // characters at ends match and either inner is palindrome
                                    // or single characters are palindromes.
            }
        }
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, part, res);
        return res;
        // precomp
        // O(n2^n) time and O(n2 extra space) besides output O(n2^n).
    }

    void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res){
        if (i >= s.length()){
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.length(); ++j){
            if (dp[i][j]){
                part.push_back(s.substr(i, j - i + 1));
                dfs(j+1, s, part, res);
                part.pop_back();
            }
        }
    }

};
