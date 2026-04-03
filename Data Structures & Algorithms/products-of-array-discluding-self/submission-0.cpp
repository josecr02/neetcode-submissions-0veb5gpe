class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        vector<int> res(n, 0);

        pref[0] = 1; // base case
        suff[n-1] = 1; // base

        for (int i = 0; i < n; ++i){
            // compute pref
            if (i > 0){
                pref[i] = pref[i-1] * nums[i-1]; // all to the left of i-1 times the number that came before.
            }
        }
        for (int i = n-2; i >=0; --i){
            suff[i] = suff[i+1] * nums[i+1]; // all to the left of i-1 times the number that came before.
        }

        for (int i = 0; i < n; ++i){
            res[i] = pref[i] * suff[i];
        }

        return res;
    }
};
