class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string res = "";
        unordered_set<string> st;
        for(string& word : words){
            if(word.length() == 1 || st.find(word.substr(0,word.length() - 1)) != st.end()){
                if(word.length() > res.length()){
                    res = word;
                }
                st.insert(word);
            }
        }
        
        return res;
    }
};