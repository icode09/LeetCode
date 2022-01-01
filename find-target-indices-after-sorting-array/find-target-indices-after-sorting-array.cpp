class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0 , rank = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == target) count++;
            if(nums[i] < target) rank++;
        }
        
        vector<int> ans;
        while(count--){
            ans.push_back(rank++);
        }
        return ans;
    }
};