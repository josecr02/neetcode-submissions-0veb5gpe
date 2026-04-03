class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // more optimal solution using deque in O(n) time and space.

       int n = nums.size();
       vector<int> output(n - k + 1);
       deque<int> q;
       int l = 0, r = 0;

       while (r < n){

        // first we remove indice in deque whose values are smaller than the new value
        // because they will never be max.
        // q.back() has current min value of the window
        while (!q.empty() && nums[q.back()] < nums[r]){
            q.pop_back();
        }

        q.push_back(r);

        // current max is on the left side of the window so it doesn't count so we go to the next max
        if (l > q.front()){
            q.pop_front();
        }

        // this will run all iterations after initial window
        if ((r + 1) >= k) // r+1 because of 0-indexed. this means that the window has updated and we have to update the max.
        {
            output[l] = nums[q.front()]; // put the max value
            ++l; // move the left pointer of window
        }
        ++r;


       }

       return output;
    }
};
