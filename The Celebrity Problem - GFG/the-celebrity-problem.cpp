// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(int i,int j,vector<vector<int>>& M){
        return M[i][j];
    }
    int findPotentialCandidate(vector<vector<int>>& M,int n){
        if(n == 0)
            return -1;
            
        int id = findPotentialCandidate(M,n-1);
        
        if(id == -1) return n-1;
        else if(knows(id,n-1,M)) return n-1;
        else if(knows(n-1,id,M)) return id;
        else return -1;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        int id = findPotentialCandidate(M,n);
        
        if(id == -1) return -1;
        
            int c1 = 0 , c2 = 0;
            for(int i = 0;i<n;i++){
                if(i != id){
                    if(knows(i,id,M)) c1++;
                    else if(knows(id,i,M)) c2++;
                }
            }
            if(c1 == n-1 && c2 == 0) 
                return id;
        
        return -1;
        
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends