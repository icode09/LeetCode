// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	long long int prime_Sum(int n){
   	    // Code here
   	    vector<bool> isprime(n+1,true);
   	    
        long long int sum = 0;
        isprime[0] = isprime[1] = false;
        
        for(int i = 2;i*i<=n;i++){
            if(isprime[i]){
                for(int j = i*i ;j<=n;j+=i){
                    isprime[j] = false;
                }
            }
        }
        
        for(int i = 2;i<=n;i++){
            if(isprime[i])
                sum += i;
        }
        
        return sum;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends