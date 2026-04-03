class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we want the index of target in nums. O(n) is trivial.
        // this approach consists of first find the pivot (smallest element in the rotated array), which
        // denotes where the array was rotated. then binary search one of the sides that has the target.
        int l = 0, r = nums.size() - 1;

        while (l < r){
            int m = (l + r) / 2;
            if (nums[m] > nums[r]){
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;
        l = 0;
        r = nums.size() - 1;
        if (target >= nums[pivot] && target <= nums[r]){
            l = pivot;
        } else {
            r= pivot - 1;
        }

        while (l <= r){
            int m = (l + r) / 2;
            if (nums[m] == target){
                return m;
            } else if (nums[m] < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
};
