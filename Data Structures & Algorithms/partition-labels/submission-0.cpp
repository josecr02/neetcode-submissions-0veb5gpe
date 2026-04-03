class Solution {
public:
    vector<int> partitionLabels(string s) {
        // keep track of chars in current substring. keep frequency map.
        // finish substring when chars in curren substring have freq rem 0.
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); ++i){
            lastIndex[s[i]] =i;
        }
        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < s.length(); ++i){
            ++size;
            end = max(end, lastIndex[s[i]]);

            if (i == end){
                res.push_back(size);
                size =0;
            }
            
        }
        return res;
    }
};
