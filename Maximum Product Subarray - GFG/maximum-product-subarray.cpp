// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    if(n == 0) return 0;
	    
	    long long curr_max_prod = arr[0];
	    long long curr_min_prod = arr[0];
	    long long res = arr[0];
	    
	    for(int i = 1;i<n;i++){
	        if(arr[i] < 0){
	            swap(curr_max_prod , curr_min_prod);
	        }
	        curr_max_prod = max((long long)arr[i], arr[i]*curr_max_prod);
	        curr_min_prod = min((long long)arr[i] , arr[i]*curr_min_prod);
	        
	        res = max(res,  curr_max_prod);
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends