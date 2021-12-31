class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for(auto val : nums){
            if(val <= c1){
                c1 = val;
            }else if(val <= c2){
                c2 = val;
            }
            else return true;
        }
        
        return false;
    }
};