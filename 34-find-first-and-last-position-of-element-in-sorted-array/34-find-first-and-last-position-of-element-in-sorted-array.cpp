class Solution {
public:
    int findFirstOccurence(vector<int>& nums,int target){
        int low = 0 , high = nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target) low = mid + 1;
            else{
                if(mid == 0 || nums[mid] != nums[mid-1]) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
    int findLastOccurence(vector<int>& nums,int target){
        int low = 0 , high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target) low = mid + 1;
            else{
                if(mid == nums.size() - 1 || nums[mid] != nums[mid+1]) return mid;
                else low = mid + 1;
            }
        }
        return -1;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        if(nums.size() == 1 && nums[0] == target) return {0,0};
        
        int lower = findFirstOccurence(nums,target);
        if(lower == -1) return {-1,-1};
        
        int upper = findLastOccurence(nums,target);
        
        return {lower,upper};
    }
};