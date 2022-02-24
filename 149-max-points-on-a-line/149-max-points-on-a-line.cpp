class Solution {
public:
    int gcd(int a,int b){
        return (b == 0) ? a : gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n <= 2) return n;
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            int count = 1, localMax = 1;
            unordered_map<string,int> mapka;
            
            for(int j = i + 1;j<n;j++){
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) count++;
                else{
                    int dy = points[j][1] - points[i][1] , dx = points[j][0] - points[i][0];
                    int g = gcd(dx,dy);
                    
                    int val = ++mapka[to_string(dy/g) + "/" + to_string(dx/g)];
                    localMax = max(localMax , val);
                }
            }
            ans = max(ans , count + localMax);
        }
        
        return ans;
    }
};