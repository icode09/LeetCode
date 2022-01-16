class Solution {
public:
    static bool mySort(const pair<char,int>& p1,const pair<char,int>& p2){
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> mapka;
        for(int i = 0;i<n;i++){
            mapka[s[i]]++;
        }
        
        string res = "";
        vector<pair<char,int>> vp;
        for(auto it: mapka)
            vp.push_back({it.first,it.second});
        
        
        sort(begin(vp),end(vp),mySort);
        
        for(auto p : vp){
            res += string(p.second,p.first);
        }
        
        return res;
    }
};