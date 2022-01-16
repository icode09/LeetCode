class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int currminn = prices[0];
        for(int i = 1;i<n;i++){
            maxProfit = max(maxProfit , prices[i] - currminn);
            currminn = min(currminn , prices[i]);
        }
        
        return maxProfit;
    }
};