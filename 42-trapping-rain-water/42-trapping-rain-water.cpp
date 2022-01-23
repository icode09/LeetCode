class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n == 1) return 0;
        
        int low = 0 , high = n-1;
        int max_left = 0 , max_right = 0;
        
        int water = 0;
        while(low <= high){
            if(height[low] <= height[high]){
                if(height[low] > max_left)
                    max_left = height[low];
                else
                    water += max_left - height[low];
                
                low++;
            }else{
                if(height[high] > max_right)
                    max_right = height[high];
                else 
                    water += max_right - height[high];
                
                high--;
            }
        }
        
        return water;
    }
};