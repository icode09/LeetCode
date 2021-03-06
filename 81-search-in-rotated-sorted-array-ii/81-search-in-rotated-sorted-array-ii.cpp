class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        
        while(low < high){
            int mid = (low + high) >> 1;
            
            if(nums[mid] == target) return true;
            else if(nums[mid] > nums[low]){
                if(target >= nums[low] && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }else if(nums[mid] < nums[high]){
                if(target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }else{
                if(nums[low] == nums[mid]) low++;
                if(nums[high] == nums[mid]) high--;
            }
        }
        
        return (nums[low] == target) ;
    }
};