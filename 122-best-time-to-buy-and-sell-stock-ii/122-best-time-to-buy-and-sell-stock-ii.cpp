class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0 , sell = 0;
        int days = prices.size();
        
        int profit = 0;
        while(buy < days && sell < days){
            while(buy + 1 < days && prices[buy] >= prices[buy + 1]) buy++;
            
            sell = buy;
            
            while(sell + 1 < days && prices[sell] < prices[sell + 1]) sell++;
            
            profit += prices[sell] - prices[buy];
            
            buy = sell + 1;
        }
        
        return profit;
    }
};