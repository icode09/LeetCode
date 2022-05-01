// { Driver Code Starts
// C++ program for pendulum arrangement of numbers
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Returns pendulam arrangement of arr[]
vector<int> pendulumArrangement(int arr[], int n) {
    sort(arr , arr + n);
    // 1 2 3 4 5

    vector<int> ans(n);
    
    int i = 0 , j = n-1;
    int k = n - 1;
    bool flag = (n%2 == 0) ? false: true;
    // 5 3 1 2 4
    while(i <= j){
        if(flag){
            ans[i] = arr[k];
            i++ , k--;
        }else{
            ans[j] = arr[k];
            j-- , k--;
        }
        
        flag = !flag;
    }
    
    return ans;
}


// { Driver Code Starts.

int main() {
    int t, i;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) cin >> arr[i];

        vector<int> ans = pendulumArrangement(arr, n);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends