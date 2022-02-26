class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";
        if(n == 1) return s;
        
        int maxStart = 0 ,maxEnd = 0 , maxLength = 1;
        
        for(int i = 0;i<n;i++){
            // expand around even centrer
            int len = 0, left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                len += 2;
                if(maxLength < len){
                    maxStart = left , maxEnd = right;
                    maxLength = len;
                }
                left-- , right++;
            }
            
            //expand around odd center
            len = 1, left = i - 1, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                len += 2;
                if(maxLength < len){
                    maxStart = left , maxEnd = right;
                    maxLength = len;
                }
                left-- , right++;
            }
        }
        
        return s.substr(maxStart , maxEnd  - maxStart + 1);
    }
};