class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxP = 0;
        while (r < prices.size()){
            if (prices[r] > prices[l]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }
            else {
                // the prices[r] is cheaper!
                l = r;
            }
            ++r;
        }
        return maxP;
    }
};
