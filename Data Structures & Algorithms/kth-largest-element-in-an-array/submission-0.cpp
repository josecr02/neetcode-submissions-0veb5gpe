class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // This is Quick Select algorithm.
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k){
        int pivot = nums[right];
        int p = left;

        for (int i = left; i < right; ++i){
            if (nums[i] <= pivot){ // all numbers <= pivot fo to the left
                swap(nums[p], nums[i]); // put the number to the left side.
                p++;
            }
        }
        swap(nums[p], nums[right]); // put the rightmost element (the pivot) at p, the pivot positionj.

        if (p > k){
            return quickSelect(nums, left, p - 1, k);
        } else if (p < k){
            return quickSelect(nums, p + 1, right, k);
        } else {
            return nums[p];
        }
    }
};
