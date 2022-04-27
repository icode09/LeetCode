// { Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




 // } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
    
        int count=0;
       int left=0,right=n-1;
       while(left<right){
           if(arr[left]+arr[right]==sum){
               count++;
               left++,right--;
           }
           else if(arr[left]+arr[right]<sum) left++;
           else right--;
       }
       return count==0?-1:count;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends