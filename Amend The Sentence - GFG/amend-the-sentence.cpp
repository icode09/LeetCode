// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string res = "";
        
        for(int i = 0;i<s.length();i++){
            if(i == 0){
                res += tolower(s[i]);
            }else if(isupper(s[i])){
                res += " ";
                res += tolower(s[i]);
            }else{
                res += s[i];
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends