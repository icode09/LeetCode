class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        istringstream ss(s);
        string word;
        while(ss >> word) v.push_back(word);
        

        if(pattern.length() != v.size()) return false;
        unordered_map<char, string> m1;
        
        for(int i=0; i<pattern.size(); i++){
            if(m1.find(pattern[i]) == m1.end()){
                m1[pattern[i]] = v[i];
            }
            else if(m1.find(pattern[i]) != m1.end()){
                if(m1[pattern[i]] != v[i]) return false;
                else continue;
            }
        }
        unordered_map<string,char> m2;
        for(int i = 0;i<v.size();i++){
            if(m2.find(v[i]) == m2.end()){
                m2[v[i]] = pattern[i];
            }
            else if(m2.find(v[i]) != m2.end()){
                if(m2[v[i]] != pattern[i]) return false;
                else continue;
            }
        }
        return true;
    }
};