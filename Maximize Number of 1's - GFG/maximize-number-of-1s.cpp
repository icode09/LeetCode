// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int k) {
        // code here
        int zeroCount = 0, left = 0;
        int maxLength = 0;
        for(int right = 0 ; right < n; right++){
            if(nums[right] == 0) zeroCount++;
            if(zeroCount > k){
                if(nums[left] == 0) zeroCount--;
                left++;
            }
            maxLength = max(maxLength , right - left + 1);
        }
        
        return maxLength;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends