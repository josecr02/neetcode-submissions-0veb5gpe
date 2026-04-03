class Solution {
public:
    bool isAnagram(string s, string t) {
        // we can have a map that maps the character in each to a pair, denoting the number of times
        // each character appears in each string. If the numbers are equal for all of them, return true.
        // this approach would be linear time
        std::unordered_map<char, std::pair<int, int>> mapCount;
        for (int i = 0; i < s.length(); ++i){
            if (mapCount.find(s[i]) == mapCount.end()){
                mapCount.insert({s[i], {1, 0}}); // first time seeing the char
            } else {
                // else we have seen the char
                // we increment count
                ++(mapCount[s[i]].first);
            }
        }
        // now we repeat with t
        for (int i = 0; i < t.length(); ++i){
            if (mapCount.find(t[i]) == mapCount.end()){
                return false; // no same characters
            } else {
                // else we have seen the char
                // we increment count
                ++(mapCount[t[i]].second);
            }
        }

        for (auto& [key, value]: mapCount){
            if (value.first != value.second){
                return false;
            }
        }
        return true;
    }
};
