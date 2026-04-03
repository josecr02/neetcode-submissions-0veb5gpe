class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // brute force, sorting
        // n2logn
        while (stones.size() > 1){
            sort(stones.begin(), stones.end()); // sorts in ascending order
            int cur = stones.back() - stones[stones.size() - 2]; // x - y
            stones.pop_back();
            stones.pop_back();
            if (cur != 0){
                // if x > y
                stones.push_back(cur);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};
