class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep a set of seen characters
        // move window while unique characters
        // keep track of max length string

        unordered_set<char> charSet;
        int l = 0;
        int res = 0; 


        for (int r = 0; r < s.size(); ++r){
            while (charSet.find(s[r]) != charSet.end()){
                // means the rightmost character is duplicated so we move forwards left to get valid substring
                charSet.erase(s[l]); // remove the leftmost character (unique in substring already  )
                ++l;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
