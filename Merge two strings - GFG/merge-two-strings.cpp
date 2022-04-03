// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
    int n = S1.length();
    int m = S2.length();
    
    int i = 0 , j = 0;
    bool flag = true;
    string res = "";
    while(i < n && j < m){
        if(flag){
            res += S1[i];
            i++;
        }else{
            res += S2[j];
            j++;
        }
        flag = !flag;
    }
    
    while(i < n){
        res += S1[i++];
    }
    
    while(j < m){
        res += S2[j++];
    }
    
    return res;
}