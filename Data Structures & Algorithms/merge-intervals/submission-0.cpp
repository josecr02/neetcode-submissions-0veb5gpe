class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_start = 0;
        for (const auto& interval : intervals){
            max_start = max(interval[0], max_start);
        }

        vector<int> mp (max_start + 1, 0); // array that holds ending values for said starts.
        for (const auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> res;
        int currentEnd = -1;
        int intervalStart = -1;
        for (int i = 0; i < mp.size(); ++i){
            if (mp[i] != 0){
                // an interval starts here
                if (intervalStart == -1) intervalStart = i;
                currentEnd = max(mp[i] - 1, currentEnd);
            }
            if (currentEnd == i){
                res.push_back({intervalStart, currentEnd});
                currentEnd = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1){
            res.push_back({intervalStart, currentEnd});
        }

        return res;
    }
};
