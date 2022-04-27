// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        long long find_multiplication(int a[], int b[], int n, int m)
    {
        // Complete the function
        int maxx = *max_element(a , a + n);
        int minn = *min_element(b , b + m);
        
        return (long long)maxx*minn;
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
        int a[n];
        for(int i=0;i<n;i++)    cin>>a[i];
        
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)    cin>>b[i];
        
        
        Solution ob;
        cout<<ob.find_multiplication(a, b, n, m)<<endl;

    }
    return 0;
}  // } Driver Code Ends