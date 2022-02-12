// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(s[i] == ']'){
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                
                int n = stoi(num);
                string repeat = "";
                for(int i = 0;i<n;i++){
                    repeat += temp;
                }
                for(char ch : repeat){
                    st.push(ch);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends