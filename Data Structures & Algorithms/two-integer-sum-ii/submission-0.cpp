class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // start l = 0, r = n-1.
        // since it's increasing, check the current sum, if sum is bigger than target, then move right pointer to left.
        // if sum is smaller, then move left pointer to right.
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r){
            int curSum = numbers[l] + numbers[r];
            if (curSum > target){
                --r;
            } else if (curSum < target){
                ++l;
            } else {
                return {l+1, r+1};
            }
        }
        return {};
    }
};
