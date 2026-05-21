class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search from max weight of package to sum of all packages.
        // we check at midpoints.
        int minShipWeight = *max_element(weights.begin(), weights.end());
        int maxShipWeight = std::accumulate(weights.begin(), weights.end(), 0);
        int ships = 1;
        int curWeight = 0;
        int l = minShipWeight;
        int r = maxShipWeight;
        int res = maxShipWeight;
        while (l <= r){
            int mWeight = (l + r) / 2;

            for (int w : weights){
                curWeight += w;
                if (curWeight > mWeight){
                    ++ships;
                    curWeight = w; // put it in a new ship.
                }
            }
            if (ships <= days){
                res = min(res, mWeight);
                r = mWeight - 1;
            } else {
                l = mWeight + 1;
            }

            ships = 1;
            curWeight = 0;
        }
        return res;
        
    }
};