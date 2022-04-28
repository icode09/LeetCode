// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mapka;
		    queue<char> q;
		    
		    string res = "";
		    for(int i = 0;i<A.length();i++){
		        if(mapka[A[i]] == 0){
		            mapka[A[i]] = 1;
		            q.push(A[i]);
		        }else{
		            mapka[A[i]]++;
		        }
		        
		        while(!q.empty() && mapka[q.front()] > 1)
		            q.pop();
		      
		        if(!q.empty())
		            res += q.front();
		        else
		            res += '#';
		    }
		    
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends