class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp
        // one scan in which we keep track of minimum buy
        // and the profit of selling the current day with the minimum buy.
        int minBuy = prices[0];
        int maxP = 0; // current best profit is 0.
        for (int& sell : prices){
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};
