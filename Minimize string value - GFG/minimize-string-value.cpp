// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int minValue(string S, int k)
	{
	    // Your code goes here
	    // k max freq characters in the string
	    int n = S.length();
	    
	    int freq[26] = {0};
	    
	    priority_queue<pair<int,int>> pq;
	    
	    for(int i = 0;i<n;i++){
	        freq[S[i] - 'a']++;
	    }
	    
	    int sum = 0;
	    for(int i = 0;i<26;i++){
	        if(freq[i] > 0){
	            pq.push({freq[i] , i});
	        }
	    }
	    
	    while(k--){
	        int idx = pq.top().second;
	        pq.pop();
	        
	        freq[idx]--;
	        pq.push({freq[idx] , idx});
	    }
	    
	    for(int i = 0;i<26;i++){
	        if(freq[i] > 0)
	            sum += freq[i]*freq[i];
	    }
	    
	    return sum;
	}
};

// { Driver Code Starts.

int main() 
{
   
   
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		int k;
   		cin >> k;
        Solution ob;

   		cout << ob.minValue(s, k);

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends