class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        
        int begin = 0 , end = 0;
        int maxLength = 1;
        int counter = 0;
        unordered_map<char,int> mapka;
        
        while(end < n){
            char windowEndChar = s[end];
            mapka[windowEndChar]++;
            
            if(mapka[windowEndChar] > 1) counter++; 
            
            end++;
            
            
            while(counter > 0){
                char windowStartChar = s[begin];
                if(mapka[windowStartChar] > 1) counter--;
                mapka[windowStartChar]--;
                begin++;
            }
            
            maxLength = max(maxLength , end - begin);
        }
        
        return maxLength;
    }
};