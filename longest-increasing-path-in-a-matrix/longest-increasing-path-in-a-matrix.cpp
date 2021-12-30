class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x,int y){
        if(dp[x][y] != -1) return dp[x][y];
        
        int max_len = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(isValid(xx,yy,matrix.size(),matrix[0].size()) && matrix[xx][yy] > matrix[x][y]){
                max_len = max(max_len , 1 + dfs(matrix,dp,xx,yy));
            }
        }
        
        return dp[x][y] = max_len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int max_len = 0;
        
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                max_len = max(max_len , 1 + dfs(matrix,dp,i,j));
            }
        }
        
        return max_len;
    }
};