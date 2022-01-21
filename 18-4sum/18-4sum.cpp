class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        set<string> st;
        vector<vector<int>> ans;
        for(int i = 0;i+3<n;i++){
            for(int j = i+1;j+2<n;j++){
                int low = j + 1;
                int high = n - 1;
                int newTarget = target - (nums[i] + nums[j]);
                while(low < high){
                    int sum = nums[low] + nums[high];
                    if(sum == newTarget){
                        string str = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[low]) + to_string(nums[high]);
                        if(st.find(str) == st.end()){
                            st.insert(str);
                            ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        }
                        low++ , high--;
                    }
                    else if(sum > newTarget) high--;
                    else low++;
                }
            }
        }
        
        return ans;
    }
};