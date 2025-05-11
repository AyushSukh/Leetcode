class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;

        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
            } else if (price - min_price > profit) {
                profit = price - min_price;
            }
        }
        return profit;
    }
};