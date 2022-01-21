class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for(int i = 0;i<n;i++){
            int start = nums[i];
            while(i + 1 < n && (nums[i+1] == 1 + nums[i])){
                i++;
            }
            int end = nums[i];
            if(start != end){
                string str = to_string(start) + "->" + to_string(end);
                ans.push_back(str);
            }else{
                ans.push_back(to_string(start));
            }
        }
        
        return ans;
    }
};