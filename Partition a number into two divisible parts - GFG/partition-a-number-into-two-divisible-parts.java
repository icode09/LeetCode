// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String str[] = read.readLine().split(" ");
            String S= str[0];
            int a = Integer.parseInt(str[1]);
            int b = Integer.parseInt(str[2]);
            Solution ob = new Solution();
            System.out.println(ob.stringPartition(S,a,b));
        }
    }
}// } Driver Code Ends


//User function Template for Java
class Solution{
    static String stringPartition(String test, int a, int b) {
        for(int i = 0;i<test.length();i++){
            String left = test.substring(0,i+1);
            String right = test.substring(i+1);
            if(isDivisible(left,a) && isDivisible(right,b)){
                return left + " " + right;
            }
        }
        return "-1";
    }

    private static boolean isDivisible(String left, int a) {
        if(left.isEmpty()) return false;
        int num = Integer.parseInt(left);
        return (num%a == 0);
    }
}