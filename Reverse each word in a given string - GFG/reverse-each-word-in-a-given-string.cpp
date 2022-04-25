// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans = "";
        int n = s.length();
        for(int i = 0;i<n;i++){
            string temp = "";
            while(i < n && s[i] != '.'){
                temp += s[i];
                i++;
            }

            reverse(temp.begin(),temp.end());
            
            ans += temp;
            if(i < n) ans += ".";
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends