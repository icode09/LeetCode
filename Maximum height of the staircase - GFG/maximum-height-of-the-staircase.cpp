// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int maxStairHeight(int N) {
        // Code here4
        return ( sqrt(1 + 8*N) - 1)/2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.maxStairHeight(N) << endl;
    }
    return 0;
}  // } Driver Code Ends