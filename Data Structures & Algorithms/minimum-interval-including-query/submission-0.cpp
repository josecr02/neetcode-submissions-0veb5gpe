class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sweep line algorithm
        // we use min heap ordered by interval size
        vector<vector<int>> events;
        // Create events for intervals
        for (int i = 0; i < intervals.size(); i++) {
            events.push_back({intervals[i][0], 0, intervals[i][1] - intervals[i][0] + 1, i});
            events.push_back({intervals[i][1], 2, intervals[i][1] - intervals[i][0] + 1, i});
        }

        // Create events for queries
        for (int i = 0; i < queries.size(); i++) {
            events.push_back({queries[i], 1, i});
        }

        // Sort by time and type (end before query)
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<int> ans(queries.size(), -1);
        // Min heap storing [size, index]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inactive(intervals.size(), false);

        for (const auto& event : events) {
            if (event[1] == 0) { // Interval start
                pq.push({event[2], event[3]});
            } else if (event[1] == 2) { // Interval end
                inactive[event[3]] = true;
            } else { // Query
                int queryIdx = event[2];
                while (!pq.empty() && inactive[pq.top().second]) {
                    pq.pop();
                }
                if (!pq.empty()) {
                    ans[queryIdx] = pq.top().first;
                }
            }
        }

        return ans;
    }
};
