// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countPairs(int X[], int Y[], int m, int n) {
        // code here
        double x[m];
        double y[n];
        
        for(int i = 0;i<m;i++){
            if(X[i] == 1){
                x[i] = DBL_MAX;
            }else{
                X[i] = X[i]*1.0;
                x[i] = X[i]/log10(X[i]);
            }
        }
        
        sort(x , x + m);
        
        for(int i = 0;i<n;i++){
            if(Y[i] == 1){
                y[i] = DBL_MAX;
            }else{
                Y[i] = Y[i]*1.0;
                y[i] = Y[i]/log10(Y[i]);
            }
        }
        
        sort(y , y + n);
        
        
        long long count = 0;
        int i = 0 , j = 0;
        
        while(i < m && j < n){
            if(x[i] < y[j]){
                count += (n - j);
                i++;
            }else {
                j++;
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int X[m], Y[n];
        for (int i = 0; i < m; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
        }
        Solution ob;
        auto ans = ob.countPairs(X, Y, m, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends