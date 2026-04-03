class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        for (char task : tasks) {
            count[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& [key, cnt]  : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // use queue if the maxHeap is empty. order is important.
            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            // analyze the front of the queue to see if its finished cooldown.
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};