class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        
        vector<int> lis(n,1);
        
        int maxxLength = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i] , lis[j] + 1);
                }
            }
            maxxLength = max(maxxLength , lis[i]);
        }
        
        return maxxLength;
    }
};