class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int size = heights.size();
        
        int i = 0, maxArea = 0;
        stack<int> st;
        while(i < size){
            if(st.empty() || heights[st.top()] <= heights[i]){
                st.push(i++);
            }else{
                int top = st.top();
                st.pop();
                
                maxArea = max(maxArea , heights[top]*(st.empty() ? i : i - st.top() - 1));
            }
        }
        
        return maxArea;
    }
};