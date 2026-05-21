class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // first get the first valid subarray
        // then add next element
        // then try removing the first element from the sum. if it's valid then continue removing. else keep it.
        // keep the min length saved.

        // O(n) time

        int res = INT_MAX;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); ++r){
            // count the element
            sum += nums[r];
            
            while (sum >= target){
                // we can shrink while keeping a valid subarray
                res = min(res, r - l + 1); // count length since its valid.
                
                sum -= nums[l];
                ++l;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};