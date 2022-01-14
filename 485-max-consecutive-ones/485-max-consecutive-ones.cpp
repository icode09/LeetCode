class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int ones = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                ones++;
                maxCount = max(maxCount , ones);
            }else {
                ones = 0;
            }
        }
        return maxCount;
    }
};