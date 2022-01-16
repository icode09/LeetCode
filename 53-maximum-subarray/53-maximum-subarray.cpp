class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int currmax = nums[0];
        int maxxSum = nums[0];
        
        for(int i = 1;i<n;i++){
            currmax = max(nums[i] , currmax + nums[i]);
            maxxSum = max(maxxSum , currmax);
        }
        
        return maxxSum;
    }
};