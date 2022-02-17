// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            dp[i][m-1] = M[i][m-1];
        }
        for(int col = m-2;col>=0;col--){
            for(int row = 0;row<n;row++){
                int right = dp[row][col+1];
                int right_up = (row == 0) ? 0 : dp[row-1][col+1];
                int right_down = (row == n-1) ? 0 : dp[row+1][col + 1];
                
                dp[row][col] = M[row][col] + max(right, max(right_up , right_down));
            }
        }
        
        int maxx = dp[0][0];
        for(int i = 1;i<n;i++){
            maxx = max(maxx , dp[i][0]);
        }
        
        return maxx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends