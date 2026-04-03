class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // we follow a greedy approach.
        // we wan to determine a starting point in which we can 
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if (totalGas < totalCost){
            return -1;
        }

        // 1 exact solution exists

        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); ++i){
            total += (gas[i] - cost[i]);
            if (total < 0){ // we cannot start from any station between res and i.
                total = 0;
                res = i + 1; // set starting point as next possible.
                // index i already fails, so we use i + 1.
            }
        }
        return res;
    }
};
