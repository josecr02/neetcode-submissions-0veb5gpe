class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // initialize a map
        std::unordered_map<std::string, std::vector<string>> anagramMap;

        for (auto s : strs){
            std::string notSorted{s};
            sort(s.begin(), s.end());
            if (anagramMap.find(s) == anagramMap.end()){
                // means sorted string is NOT in the map.
                anagramMap.insert({s, vector<string>{}}); // s and the vector is of 1 element
            } 
                // the key already existed
            anagramMap[s].push_back(notSorted);
            
        }

        std::vector<vector<string>> result;
        for (auto element : anagramMap){
            result.push_back(element.second);
        }

        return result;
    }
};
