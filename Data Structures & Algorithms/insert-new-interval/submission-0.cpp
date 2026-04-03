class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // we follow greedy format.
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i){
            vector<int>& currentInterval = intervals[i];
            if (newInterval[1] < currentInterval[0]){
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            else if (newInterval[0] > currentInterval[1]){
                res.push_back(currentInterval);
            } else {
                // overlap
                newInterval[0] = min(newInterval[0], currentInterval[0]);
                newInterval[1] = max(newInterval[1], currentInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
