class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n == 1) return 0;
        
        int prefix[n];
        prefix[0] = height[0];
        for(int i = 1;i<n;i++){
            prefix[i] = max(prefix[i-1] , height[i]);
        }
        
        int suffix[n];
        suffix[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1] , height[i]);
        }
        
        int water = 0;
        
        for(int i = 1;i+1<n;i++){
            int var = min(prefix[i-1] , suffix[i+1]);
            if(var > height[i]){
                water += var - height[i];
            }
        }
        
        return water;
    }
};