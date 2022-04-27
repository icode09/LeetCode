// { Driver Code Starts


// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int primeSetBits(int L, int R){
        // code here
        int i,j,n=R+1;
       bool isprime[n];
       fill_n(isprime,n,true);
       isprime[0]=isprime[1]=false;
       for(i=2;i<n;i++){
           if(isprime[i]==true){
               for(j=2*i;j<n;j+=i){
                   isprime[j]=false;
               }
           }
       }
       int ans=0;
       for(i=L;i<=R;i++){
           int c=0;
             j=i;
           while(j){
               c++;
               j=j&(j-1);
           }
           if(isprime[c]==true) ans++;
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.primeSetBits(L,R)<<endl;
    }
    return 0;
}
  // } Driver Code Ends