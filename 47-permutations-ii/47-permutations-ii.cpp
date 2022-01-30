class Solution {
public:
    void recur(vector<int> nums,vector<vector<int>>& res,int start){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = start;i<nums.size();i++){
            if(i != start && nums[i] == nums[start]) continue;
            
            swap(nums[i],nums[start]);
            recur(nums,res,start+1);
            // swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        recur(nums,res,0);
        
        return res;
    }
};