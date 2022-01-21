class Solution {
public:
    int findCandidate(vector<int>& nums){
        int major = 0 , counter = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[major]) counter++;
            else counter--;
            
            if(counter == 0){
                major = i;
                counter = 1;
            }
        }
        
        return nums[major];
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int candidate = findCandidate(nums);
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == candidate) count++;
        }
        
        if(count > n/2) return candidate;
        else return -1;
    }
};