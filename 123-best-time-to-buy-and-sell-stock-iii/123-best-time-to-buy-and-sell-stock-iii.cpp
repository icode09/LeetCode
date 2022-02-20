class Solution {
public:
    int dp[100001][2][2];
    int profit(vector<int>& prices,int i,int hold,int k){
        if(i == prices.size() || k == 2) return 0;
        
        if(dp[i][hold][k] != -1) return dp[i][hold][k];
        
        int ans = 0;
        if(hold){
            int sell = profit(prices,i+1,!hold,k+1) + prices[i];
            int no_sell = profit(prices,i+1,hold,k);
            ans = max(sell , no_sell);
        }else{
            int buy = profit(prices,i+1,!hold,k) - prices[i];
            int no_buy = profit(prices,i+1,hold,k);
            
            ans = max(buy , no_buy);
        }
        
        return dp[i][hold][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1 , sizeof dp);
        return profit(prices,0,0,0);
    }
};