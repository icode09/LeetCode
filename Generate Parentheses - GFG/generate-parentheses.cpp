// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(string res, int open , int close , vector<string>& ans){
        if(!open && !close){
            ans.push_back(res);
            return;
        }
        
        if(open){
            solve(res + "(", open - 1, close,ans);
        }
        if(close && close > open){
            solve(res + ")", open , close - 1, ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        if(!n) return {};
        vector<string> ans;
        solve("" , n , n , ans);
        
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends