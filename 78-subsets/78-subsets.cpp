class Solution {
public:
    void recur(vector<int>& nums,int index,string str, vector<int>& temp,vector<vector<int>>& res){
        res.push_back(temp);
        
        for(int i = index ; i < nums.size();i++){
            temp.push_back(nums[i]);
            recur(nums,i + 1,str + to_string(nums[i]),temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return {};
        
        vector<vector<int>> res;
        vector<int> temp;
        recur(nums,0,"",temp,res);
        
        return res;
    }
};