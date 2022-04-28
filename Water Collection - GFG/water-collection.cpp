// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int maxWater(int arr[], int n) {
            // code here 
            
        int left = 0 , right = n - 1;
        
        int waterCollected = 0;
        int max_left = 0 , max_right = 0;
        
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] > max_left)
                    max_left = arr[left];
                else
                    waterCollected += (max_left - arr[left]);
                    
                left++;
            }else{
                if(arr[right] > max_right)
                    max_right = arr[right];
                else
                    waterCollected += (max_right - arr[right]);
                    
                right--;
            }
        }
        
        return waterCollected;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxWater(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends