class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int count[1001] = {0};
        for(int i = 0;i<trips.size();i++){
            count[trips[i][1]] += trips[i][0];
            count[trips[i][2]] -= trips[i][0];
        }
        
        for(int i = 0;i<=1000;i++){
            if(capacity < 0) break;
            capacity -= count[i];
        }
        
        return capacity >= 0;
    }
};