// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int odd = 0 , even = 0;
	    int n = s.length();
	    for(int i = 0;i<n;i++){
	        if(s[i] == '1'){
	            if(i & 1) odd++;
	            else even++;
	        }
	    }
	    
	    return abs(even - odd)%3 == 0;
	}
//   1100 = 12
//   0101 = 9
//   0110  = 6
//   0011 = 3
};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends