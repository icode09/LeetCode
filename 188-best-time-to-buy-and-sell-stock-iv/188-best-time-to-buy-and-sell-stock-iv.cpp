class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(k >= n/2){
            int profit = 0;
            for(int i = 1;i<n;i++){
               if(prices[i] > prices[i-1]) 
                   profit += prices[i] - prices[i-1];
            }
            return profit;
        }
        
        vector<int> buy(k+1,INT_MIN);
        vector<int> profit(k+1 , 0);
        
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=k;j++){
                buy[j] = max(buy[j] , profit[j-1] - prices[i]);
                profit[j] = max(profit[j] , buy[j] + prices[i]);
            }
        }
        
        return profit[k];
    }
};