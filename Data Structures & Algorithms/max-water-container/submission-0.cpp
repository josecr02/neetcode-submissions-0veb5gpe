class Solution {
public:
    int maxArea(vector<int>& heights) {
        // two pointers.
        // we start off with largest width and move side that has shorter length
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);
            if (heights[l] <= heights[r]){
                ++l;
            } else {
                r--;
            }
        }
        return res;
    }
};
