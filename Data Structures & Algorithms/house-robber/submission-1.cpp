class Solution {
public:
    int rob(vector<int>& nums) {
        //vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int prevRob1 = 0, prevRob2 = 0;

        for (int i = 0; i < nums.size(); ++i){ // O(n)
            //dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            int newMax = max(prevRob1 + nums[i], prevRob2); // prevRob2 is the most recent rob
            prevRob1 = prevRob2; // most recent rob is now the previous one because were stealing
            prevRob2 = newMax; // new rob is the newest max value
        }
        return prevRob2;
    }
};
