class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return {};
        
        sort(begin(nums) , end(nums));
        vector<vector<int>> res;
        for(int i = 0;i+2<n;i++){
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            
            int low = i + 1 , high = n - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum > 0) high--;
                else if(sum < 0) low++;
                else {
                    res.push_back({nums[i],nums[low],nums[high]});
                    
                    while(high - 1 >= 0 && nums[high] == nums[high-1]) high--;
                    while(low + 1 < n && nums[low] == nums[low + 1]) low++;
                    
                    low++ , high--;
                }
            }
        }
        
        return res;
    }
};