class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // mergesort.
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r){
        // base case is l >= r
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }

    void merge(vector<int>& nums, int l, int m, int r){
        vector<int> temp;
        int i = l, j = m+1; // at beginning of each. now we go one by one merging.

        while (i <= m && j <= r){
            if (nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                ++i;
            } else {
                temp.push_back(nums[j]);
                ++j;
            }
        }

        // now we have either merged completely, or one of them still needs to be added
        while (i <= m){
            temp.push_back(nums[i]); ++i;
        }
        while (j <= r){
            temp.push_back(nums[j]); ++j;
        }

        // now temp has merge sorted it!
        // we move the result
        for (int k = l; k <= r; ++k){
            nums[k] = temp[k - l];
        }
    }
};