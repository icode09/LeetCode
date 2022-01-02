class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
         int n = time.size();
        int freq[61] = {0};
        int res = 0;
        for(int i = 0;i<n;i++){
            time[i] %= 60;
            if(freq[60-time[i]] > 0){
                res += freq[60 - time[i]];
            }
            if(time[i] == 0) time[i] = 60;
            
            freq[time[i]]++;
        }
        
        return res;
    }
};