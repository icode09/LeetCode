class Solution {
public:
    double myPow(double x, int n) {
       double ans = 1.0;
        while(n){
            if(n%2 != 0 && n < 0) ans = ans*1/x;
            else if(n%2 != 0 && n > 0) ans = ans*x;
            
            x = x*x;
            n = n/2;
        }
        
        return ans;
    }
};