class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() || start < 0) return false;
        if(arr[start]== -1) return false;
        if(!arr[start]) return true;
        
        int leftside= start-arr[start] ,rightside = start+arr[start];
        arr[start] = -1;
        
        return (canReach(arr,rightside) ) || (canReach(arr,leftside) );
        
    }
};