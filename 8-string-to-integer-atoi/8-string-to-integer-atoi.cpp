class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        
        if(n == 0) return 0;
        
        int i = 0;
        while(s[i] == ' ') i++;
        
        int sign = 1 ,base = 0;
        if(s[i] == '-' || s[i] == '+'){
            sign = 1 - 2*(s[i] == '-');
            i++;
        }
        
        while(s[i] >= '0' && s[i] <= '9'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i] - '0' > INT_MAX%10)){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base = base*10 + (s[i] - '0');
            i++;
        }
        
        return base*sign;
    }
};