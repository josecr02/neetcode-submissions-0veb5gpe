class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int res = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for (char c : charSet) {
            int count = 0, l = 0; // count is the number of times c appears in window.
            for (int r = 0; r < s.size(); r++) { // slide the window
                if (s[r] == c) {
                    count++;
                }

                while ((r - l + 1) - count > k) { // current window needs more than k replacements. adjust.
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }

                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};