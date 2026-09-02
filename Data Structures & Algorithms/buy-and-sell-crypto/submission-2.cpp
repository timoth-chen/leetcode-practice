class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int sell: prices){
            profit = max(profit, sell - buy);
            buy = min(sell, buy);
        }
        return profit;
    }
};
