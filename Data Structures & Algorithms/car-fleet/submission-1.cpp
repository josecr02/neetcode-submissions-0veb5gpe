class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // iteration instead.
        int n = position.size();
        vector<pair<int,int>> pairs;
        for (int i = 0; i < n; ++i){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        int fleets = 1;
        double prevTime = (double)(target - pairs[0].first) / pairs[0].second;
        for (int i = 1; i < n; ++i){
            double currTime = (double)(target - pairs[i].first) / pairs[i].second; // distance / speed = time
            if (currTime > prevTime){
                // current time is bigger so it wont catch up
                ++fleets;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
