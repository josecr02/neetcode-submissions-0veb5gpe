class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // bit manipulation
        // number that appears twice cancel each other with XOR
        int res = 0;
        for (int num : nums){
            res ^= num;
        }
        return res;
    }
};
