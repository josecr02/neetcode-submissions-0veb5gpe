class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        // improved solution is to map char to the last index it appears in the string
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            // 
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l); // move the pointer to the positiono where char doesnt appear anymore
            }
            mp[s[r]] = r; // now the char appears in the new char we have seen
            res = max(res, r - l + 1);
        }
        return res;
    }
};
