class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s,0,path,res);
        
        return res;
    }
    void dfs(string& s, int index, vector<string>& path,vector<vector<string>>& res){
        if(index == s.length()){
            res.push_back(path);
            return;
        }
        
        for(int i = index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index, i - index + 1));
                dfs(s,i + 1,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string& s,int start,int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++ , end--;
        }
        return true;
    }
};