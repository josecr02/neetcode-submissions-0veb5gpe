class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // valid solution with max heap O(nlogn) time O(n) space
        // top has max value of window
        // solution 3
        priority_queue<pair<int,int>> heap;
        vector<int> output;

        for (int i = 0; i < nums.size(); ++i){
            heap.push({nums[i], i});
            if (i >= k - 1) // window updates
            {
                while (heap.top().second <= i - k){
                    // remove the current max while the current max its not in the new window
                    heap.pop();
                }

                // current mx is in the window
                output.push_back(heap.top().first);
            }
        }

        return output;
    }
};
