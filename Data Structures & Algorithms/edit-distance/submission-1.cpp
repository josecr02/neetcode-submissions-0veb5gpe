class Solution {
public:
    int minDistance(string word1, string word2) {
        // space optimized just keeping current row (i+1) nd next row(i).
        int m = word1.size(), n = word2.size();
        if (m < n) {
            swap(m, n);
            swap(word1, word2);
        }

        vector<int> dp(n + 1), nextDp(n + 1);

        for (int j = 0; j <= n; ++j) {
            dp[j] = n - j; // case word1 is empty, we insert all characters left of word2
        }

        for (int i = m - 1; i >= 0; --i) {
            nextDp[n] = m - i; // if word2 empty left, then we have to delete all left of word1
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    nextDp[j] = dp[j + 1];
                } else {
                    nextDp[j] = 1 + min({dp[j], nextDp[j + 1], dp[j + 1]});
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};