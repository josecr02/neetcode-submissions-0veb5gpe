class Solution {
public:
    int jump(vector<int>& nums) {
        // optimal greedy, O(n)
        int res = 0;
        int l = 0;
        int r = 0;
        // nums[i] is the max length of the jump, meaning we can jump to any index up to i + j
        while (r < nums.size() - 1){
            int farthest = 0;
            for (int i = l; i <= r; ++i){
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            ++res;
        }
        return res;
    }
};
