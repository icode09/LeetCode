class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length() ; 
        int m = t.length();
        
        if(m > n) return "";
        
        unordered_map<char,int> mapka;
        for(int i = 0;i<m;i++){
            mapka[t[i]]++;
        }
        
        int start = 0 , end = 0 , minStart = 0;
        int counter = mapka.size();
        int minLength = INT_MAX;
        
        while(end < n){
            mapka[s[end]]--;
             if(mapka[s[end]] == 0)
                counter--;
            
            end++;
            
            while(counter == 0){
                mapka[s[start]]++;
                
                if(mapka[s[start]] > 0)
                    counter++;
                
                if(end - start < minLength){
                    minStart = start;
                    minLength = end - start;
                }
                
                start++;
            }
        }
        
        return minLength == INT_MAX ? "" : s.substr(minStart,minLength);
    }
};