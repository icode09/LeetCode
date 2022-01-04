class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        if(n == 0) return 0;
        
        vector<int> ans = triangle[n - 1];
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                ans[j] = triangle[i][j] + min(ans[j],ans[j+1]);
            }
        }
        return ans[0];
    }
};