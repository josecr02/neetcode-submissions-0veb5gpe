class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // with recursion  (not optimal), O(N! n2)
        // algorithm: Recursively call permute(nums[1:]) to get permutations of the smaller list.
        // then for each, insert nums[0] at every position of that permutation.
        if (nums.empty()){
            return {{}};
        }

        vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(tmp);
        vector<vector<int>> res;
        for (const auto& p : perms){
            for (int i = 0; i <= p.size(); ++i){ // including last position
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]); // add the element
                res.push_back(p_copy); // add to result the new permutation
            }
        }
        return res;
    }
};
