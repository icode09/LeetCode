// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    // Complete the function
    int len = 0;
    
    for(int i = 0;i<n;i++){
        len += arr[i];
    }
    
    if(len == 0) return -1;
    
    int curr_len = 0 ;
    
    for(int i = 0;i<len;i++){
        curr_len += arr[i];
    }
    
    int maxLength = curr_len;
    
    for(int i = 1;i+len - 1 < n; i++){
        if(arr[i-1])
            curr_len--;
        if(arr[i + len - 1])
            curr_len++;
            
        if(curr_len > maxLength)
            maxLength = curr_len;
    }
    
    return len - maxLength;
    
}