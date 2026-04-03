class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // current max is eating the largest pile.
        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;

            long long totalTime = 0; // long because it could exceed 32 bits!
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h) { // time required fits within the allowed hours.
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};