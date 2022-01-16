class Solution {
public:
    bool rotateString(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n != m) return false;
        if(s == t) return true;
        
        s = s + s;
        return s.find(t) != string::npos;
    }
};