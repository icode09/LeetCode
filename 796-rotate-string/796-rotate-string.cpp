class Solution {
public:
    bool rotateString(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n != m) return false;
        if(s == t) return true;
        
        for(int i = 0;i<n;i++){
            string res = s.substr(i+1) + s.substr(0,i+1);
            // cout<<res<<endl;
            if(res == t) return true;
        }
        
        return false;
    }
};