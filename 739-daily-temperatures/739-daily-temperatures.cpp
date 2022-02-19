class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n = temp.size();
        vector<int> ans(n,0);
        
        for(int i = 0;i<(int)temp.size();i++){
            while(!st.empty() && st.top().first < temp[i]){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i] , i});
        }
        
        return ans;
    }
};