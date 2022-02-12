class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        bool dp[n+1][m+1];
        
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0){
                    char pch = p[i-1];
                    if(pch == '*') dp[i][j] = dp[i-2][j];
                    else dp[i][j] = false;
                } 
                else{
                    char pch = p[i-1];
                    char sch = s[j-1];
                    
                    if(pch == '*'){
                        dp[i][j] = dp[i-2][j];
                        char psch = p[i-2];
                        if(psch == '.' || psch == sch) dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                    else if(pch == sch || pch == '.') dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};