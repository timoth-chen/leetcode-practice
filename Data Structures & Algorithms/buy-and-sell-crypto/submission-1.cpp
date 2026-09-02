class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int price: prices){
            buy = min(price, buy);
            profit = max(profit, price - buy);
        }
        return profit;
    }
};
