class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]*arr[i-1];
        }
        
        vector<int> suffix(n);
        vector<int> res(n);
        suffix[n-1] = 1;
        res[n-1] = suffix[n-1]*prefix[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*arr[i+1];
            res[i] = prefix[i] * suffix[i];
        }
        
        return res;
    }
};