class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        
        int sum = accumulate(begin(nums),end(nums) , 0);
        int leftSum = 0;
        for(int i = 0;i<nums.size();i++){
            int rightSum = sum - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};