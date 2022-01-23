class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int size = heights.size();
        
        int maxArea = 0;
        stack<int> st;
        
        for(int i = 0;i<size;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                
                int l = (st.empty()) ? -1  : st.top();
                maxArea = max(maxArea, height*(i - l -1));
            }
            st.push(i);
        }
        
        return maxArea;
    }
};