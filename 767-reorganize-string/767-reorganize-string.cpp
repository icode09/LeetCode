class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        if(n == 0) return s;
        
        int freq[26] = {0};
        for(int i = 0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        int maxxFreq = 0;
        int letterIdx = 0;
        
        for(int i = 0;i<26;i++){
            if(freq[i] > maxxFreq){
                maxxFreq = freq[i];
                letterIdx = i;
            }
        }
        
        if(maxxFreq > (n + 1)/2) return "";
        
        int idx = 0 ;
        string res(n,' ');
        while(freq[letterIdx] > 0){
            res[idx] = (char)(letterIdx + 'a');
            idx += 2;
            freq[letterIdx]--;
        }
        
        
        for(int i = 0;i<26;i++){
            while(freq[i] > 0){
                if(idx >= n){
                    idx = 1;
                }
                res[idx] = (char)(i + 'a');
                idx += 2;
                freq[i]--;
            }
        }
        
       return res; 
        
    }
};