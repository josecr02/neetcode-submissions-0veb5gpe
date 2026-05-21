class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minShipWeight = *max_element(weights.begin(), weights.end());
        int ships = 1;
        int curWeight = 0;
        while (true){
            for (int w : weights){
                curWeight += w;
                if (curWeight > minShipWeight){
                    ++ships;
                    curWeight = w; // put it in a new ship.
                }
            }
            if (ships <= days) return minShipWeight;
            ships = 1;
            minShipWeight++;
            curWeight = 0;
        }
        return 0;
        
    }
};