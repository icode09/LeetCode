// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int isGoodorBad(string S) {
        // code here
        int v = 0 , c= 0;
        for(int i = 0;i<S.length();i++){
            if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u'){
                v++;
                c = 0;
            }else{
                c++;
                v = 0;
            }
            if(v > 5 || c > 3) return 0;
        }
        
        
        
        return 1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends