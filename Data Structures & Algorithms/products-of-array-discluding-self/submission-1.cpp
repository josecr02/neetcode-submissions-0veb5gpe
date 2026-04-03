class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; ++i){
            // compute pref
            res[i] = res[i-1] * nums[i-1]; // all to the left of i-1 times the number that came before.
        }
        //In the second pass, we multiply each res[i] with the product 
        // of all elements to the right of i (postfix product).
        int rightSideOfIProduct = 1;
        for (int i = n-1; i >=0; --i){
            res[i] *= rightSideOfIProduct; // all to the left of i-1 times the number that came before.
            rightSideOfIProduct *= nums[i];
        }

        return res;
    }
};
