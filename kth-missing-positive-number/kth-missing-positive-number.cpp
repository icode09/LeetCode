class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto val : arr){
            if(val <= k) k++;
            else break;
        }
        return k;
    }
};