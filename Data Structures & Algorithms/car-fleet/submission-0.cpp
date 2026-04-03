class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for (int i = 0; i < position.size(); ++i){
            pairs.push_back({position[i], speed[i]}); // pair up all cars
        }
        sort(pairs.rbegin(), pairs.rend()); // reverse beginning
        vector<double> fleetStack;
        for (auto& p : pairs){
            fleetStack.push_back((double)(target - p.first) / p.second); // time it takes to reach.
            if (fleetStack.size() >= 2 && fleetStack.back() <= fleetStack[fleetStack.size() - 2]){
                fleetStack.pop_back(); // new car time is less then previous car, so it catches up.
            }
        }
        return fleetStack.size();
    }
};
