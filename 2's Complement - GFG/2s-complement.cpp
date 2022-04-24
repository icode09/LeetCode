// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string complement(string bi){
        // code here
        //2's complement of a number =  1s complement + 1
        for(int i = 0;i<bi.size();i++){
            if(bi[i] == '1') bi[i] = '0';
            else bi[i] = '1';
        }
        int i;
        for(i = bi.size() - 1;i>=0;i--){
            if(bi[i] == '1') bi[i] = '0';
            else {
                bi[i] = '1';
                break;
            }
        }
        // if(i == -1){
        //     string res = "1" + bi;
        //     return res;
        // }
        
        return bi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string bi;
        cin>>bi;
        
        Solution ob;
        cout<<ob.complement(bi)<<endl;
    }
    return 0;
}  // } Driver Code Ends