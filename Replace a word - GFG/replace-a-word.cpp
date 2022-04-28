// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string replaceAll(string str, string oldW, string newW) {
        // code here
        int n1= str.length();
        int n2 = oldW.length();
        
        string res = "";
        
        for(int i = 0;i<n1;i++){
            if(str.substr(i,n2) == oldW){
                res += newW;
                i += (n2 - 1);
            }else{
                res += str[i];
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string S, oldW, newW;
        getline(cin, S);
        getline(cin, oldW);
        getline(cin, newW);
        Solution ob;
        cout << ob.replaceAll(S, oldW, newW) << endl;
    }
    return 0;
}
  // } Driver Code Ends