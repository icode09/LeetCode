// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    // Code here.
		    int base = 1 , decimal_val = 0;
		    
		    for(int i = str.length() - 1;i>=0;i--){
		        if(str[i] == '1')
		           decimal_val += base;
		        
		        base *= 2;
		    }
		    
		    return decimal_val;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string str;
    	cin >> str;
    	Solution ob;
    	int  ans = ob.binary_to_decimal(str);
    	cout << ans <<"\n";
    }
	return 0;
}  // } Driver Code Ends