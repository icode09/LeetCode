class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int> st;
        unordered_map<int,int> mapka;
        int n = nums2.size();
        for(int i = 0;i<n;i++){
            if(st.empty()) st.push(nums2[i]);
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    mapka[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        
        int m = nums1.size();
        vector<int> ans(m);
        
        for(int i = 0;i<m;i++){
            ans[i] = (mapka[nums1[i]] > 0) ? mapka[nums1[i]] : -1;
        }
        
        return ans;
    }
};