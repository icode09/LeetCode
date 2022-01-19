class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int m1 = 0 , m2 = nums[0];
        int m3 = m2;
        
        for(int i = 1;i<n;i++){
            m2 = max(m2 , m1 + nums[i]);
            m1 = m3;
            m3 = m2;
        }
        
        return m2;
    }
};