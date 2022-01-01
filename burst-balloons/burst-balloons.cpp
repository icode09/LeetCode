class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return maxCoinsMemoized(nums,0,n-1,dp);
    }
    int maxCoinsMemoized(vector<int>& nums,int start,int end,vector<vector<int>>& dp){
        if(start > end) 
            return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int maxx = nums[start];
        for(int i = start ;i <= end;i++){
            int val = maxCoinsMemoized(nums,start,i-1,dp)
                      + get(nums,i)*get(nums,start-1)*get(nums,end+1)
                      + maxCoinsMemoized(nums,i+1,end,dp);
            
            maxx = max(maxx , val);
        }
        
        return dp[start][end] = maxx;
    }
    int get(vector<int>& nums,int i){
        if(i == -1 || i == nums.size())
            return 1;
        
        return nums[i];
    }
    
    
};