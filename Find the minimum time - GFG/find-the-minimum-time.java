// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String arr[] = in.readLine().trim().split("\\s+");
            int S1 = Integer.parseInt(arr[0]);
            int S2 = Integer.parseInt(arr[1]);
            int N = Integer.parseInt(arr[2]);
            
            Solution ob = new Solution();
            System.out.println(ob.minTime(S1, S2, N));
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution{
    static int minTime(int S1, int S2, int N)
    {
        // code here
        int low = 1, high = Math.max(S1,S2)*N;
        while(low < high){
            int mid = (low + high) >> 1;
            int docs = (mid/S1 + mid/S2);
            if(docs < N) low = mid + 1;
            else high = mid;
        }
        
        return high;
    }
}