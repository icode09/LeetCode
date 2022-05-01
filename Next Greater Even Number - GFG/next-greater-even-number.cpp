// { Driver Code Starts
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long getNextEven(string x)
    {
        // Your code goes here   
        int n = x.size();
        int iteration = 1;
        while(true){
            int i = n - 1;
            
            while(i >= 1 && x[i] <= x[i-1])
                i--;
                
            if(i == 0)
                return (long long )-1;
                
            int j = n -1;
            
            while(x[j] <= x[i-1])
                j--;
            
            swap(x[j] , x[i-1]);
            
            reverse(x.begin() + i , x.end());
            
            if((x[n-1] - '0')%2 == 0)
                return stoll(x);
            
        }
        
        return (long long)-1;
    }
};

// { Driver Code Starts.
int main() 
{
	int t;
	cin >> t;
	while(t--){
    	string x;
    	cin >> x;
    	Solution ob;
        cout<< ob.getNextEven(x) <<endl;
	}
	
	return 0;
}  // } Driver Code Ends