class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // O(nlogn).
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i]; // sum of subarray [:i], in example: 2, 3, 8, 9, 14, 17
        }

        int res = n + 1;
        for (int i = 0; i < n; i++) {
            int l = i, r = n; // binary search
            while (l < r) {
                int mid = (l + r) / 2;
                int curSum = prefixSum[mid + 1] - prefixSum[i]; // sum of subarry of [i:mid].
                if (curSum >= target) {
                    r = mid;
                } else {
                    l = mid + 1; 
                }
            } // now, we have smallest j such that the subarray is bigger than target.
            if (l != n) {
                res = min(res, l - i + 1); // account for it.
            }
        }

        return res % (n + 1);
    }
};