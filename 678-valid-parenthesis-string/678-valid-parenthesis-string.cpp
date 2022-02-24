class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int minRange = 0 , maxRange = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                minRange++ , maxRange++;
            }else if(s[i] == '*'){
                maxRange++ , minRange = max(minRange - 1,0);
            }else{
                maxRange--;
                minRange = max(minRange - 1 , 0);
            }
            
            if(maxRange < 0) return false;
        }
        return minRange == 0;
    }
};