class Solution {
public:
    long long nCr(int n,int r){
        if(r > n - r)
            r = n - r;
        
        long long res = 1;
        for(int i = 0;i<r;i++){
            res *= (n - i);
            res /= (i + 1);
        }
        
        return res;
    }
    int numTrees(int n) {
        return nCr(2*n , n)/(n + 1);
    }
};