class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        if(n <= 2) return n;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int cnt = 0;
                
                if (p[i][0]==p[j][0] and p[i][1]==p[j][1]) {
                    for (int k=0; k<n; ++k)
                        if (p[k][0]==p[i][0] and p[k][1]==p[i][1]) ++cnt;
                }
                
                else {
                
                    for (int k=0; k<n; ++k) {
                        if (static_cast<long>(p[k][1]-p[i][1]) * static_cast<long>(p[j][0]-p[i][0]) == static_cast<long>(p[j][1]-p[i][1]) * static_cast<long>(p[k][0]-p[i][0])) ++cnt;
                    }
                }
                
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};