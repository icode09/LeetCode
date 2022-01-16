class Solution {
public:
    bool isMatching(char& a, char& b){
        if(a == '{' && b == '}') return true;
        else if(a == '(' && b == ')') return true;
        else if(a == '[' && b == ']') return true;
        else return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(st.empty() || s[i] == '{' || s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                if(!isMatching(top,s[i])) return false;
            }
        }
        return (st.empty()) ? true : false;
    }
};