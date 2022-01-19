class Solution {
public:
    int countPrimes(int n) {
        if(n == 1 || n == 0) return 0;
        vector<int> primes(n,true);
        primes[0] = false;
        primes[1] = false;
        
        for(int i = 2;i*i<n;i++){
            if(primes[i]){
                for(int j = i*i;j<n;j+=i)
                    primes[j] =false;
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(primes[i])
                count++;
        }
        
        return count;
    }
};