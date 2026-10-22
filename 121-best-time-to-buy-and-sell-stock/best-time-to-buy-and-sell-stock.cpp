class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        int profit;
        for(int i=0; i<prices.size();i++){
            profit=prices[i]-minPrice;
            maxProfit=max(maxProfit, profit);
            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit;
    }
};