// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    int leastSoFar = INT_MAX, left = 0, right = 0;
	   for(int i = n - 1; i >= 0; i--){
	       leastSoFar = min(leastSoFar, arr[i]);
	       if(leastSoFar != arr[i]){
	           left = i;
	       }
	   }
	   int maxSoFar = INT_MIN;
	   for(int i = 0; i < n; i++){
	       maxSoFar = max(maxSoFar, arr[i]);
	       if(maxSoFar != arr[i]){
	           right = i;
	       }
	   }
	   return {left, right};
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends