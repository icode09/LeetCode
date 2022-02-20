class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int leftMin = prices[0] , rightMax = prices[n-1];
        int left[n] , right[n];
        left[0] = 0;  right[n-1] = 0;
        for(int i = 1 , j = n-2 ; i < n && j >= 0 ; i++ , j--){
            leftMin = min(leftMin , prices[i]);
            left[i] = max(left[i-1] , prices[i] - leftMin);
            rightMax = max(rightMax , prices[j]);
            right[j] = max(right[j+1] , rightMax - prices[j]);
        }
        
        int maxxProfit = 0;
        
        for(int i = 0;i<n;i++){
            maxxProfit = max(maxxProfit, left[i] + right[i]);
        }
        
        return maxxProfit;
    }
};