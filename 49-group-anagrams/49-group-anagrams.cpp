class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapka;
        for(auto& s : strs){
            mapka[count_sort(s)].push_back(s);
        }
        vector<vector<string>> ans;
        
        for(auto it : mapka){
            ans.push_back(it.second);
        }
        
        return ans;
    }
    
    string count_sort(string& str){
        int freq[26] = {0};
        for(auto& ch : str){
            freq[ch-'a']++;
        }
        
        string res = "";
        for(int i = 0;i<26;i++){
            res += string(freq[i],(char)(i + 'a'));
        }
        
        return res;
    }
};