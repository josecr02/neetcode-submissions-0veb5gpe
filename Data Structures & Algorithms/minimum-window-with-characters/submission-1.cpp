class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char,int> countT, window;
        for (char c : t){
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int,int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        // expand window and add characters to map.
        for (int r = 0; r < s.length(); ++r){
            char c = s[r];
            window[c]++;

            // we have another character that we needed.
            if (countT.count(c) && window[c] == countT[c]){
                ++have;
            }

            // the window has all required characters, so we shrink it from the left
            while (have == need){
                if ((r - l + 1) < resLen){ // update result if it is better
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    --have; // now we dont have a needed character.
                }
                ++l; // move l to right
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
