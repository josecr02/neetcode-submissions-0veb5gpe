class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // since nums are in 1..n, then we mark the index of num we see as negative,
        // if we see it and is negative, then that number is a duplicate!
        for (int num : nums){
            int idx = abs(num) - 1;
            if (nums[idx] < 0){
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};
