class Solution {
public:
    int findMin(vector<int> &nums) {
        // the array was sorted in ascending order and then rotated
        // so the minimum element is the first element of the rotation.
        // so we do BS.
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]){
                // middle is less than right 
                r = m; // min is on left
            } else {
                l = m + 1; // min is on the right
            }
        }
        return nums[l];
    }
};
