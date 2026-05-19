class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // keep a max heap of tasks by their remaining count
        // take the most frequent available and run it. keep timer.
        // then put it in a cooldown queue (available at time + n).
        // when cooled, push it back again.
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }
        // the queue stores (count after running, next available time).
        queue<pair<int,int>> q;
        int time = 0;
        // iterate while we have elements to take
        while (!maxHeap.empty() || !q.empty()){
            ++time;
            // first take off the heap
            if (!maxHeap.empty()){
                int currentMostFreqCount =  maxHeap.top();
                maxHeap.pop();
                currentMostFreqCount--;
                if (currentMostFreqCount > 0){
                    q.push({currentMostFreqCount, time + n});
                }
            }
            if (!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
