class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // same but now iteration

        vector<vector<int>> res {{}}; // start with empty subset

        for (int num : nums){
            int size = res.size(); // number of subsets at this point
            // add to all of them this new number
            for (int i = 0; i < size; ++i){
                vector<int> subset = res[i]; // copy!
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};
