class Solution {
public:
   set<vector<int>> st;
    void permute(vector<vector<int>>& res,vector<int>& nums,int index){
        if(index == nums.size()){
            if(st.find(nums) == st.end()){
                res.push_back(nums);
                st.insert(nums);
                return;
            }
        }
        for(int i = index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permute(res,nums,index + 1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res,nums,0);
        
        return res;
    }
};