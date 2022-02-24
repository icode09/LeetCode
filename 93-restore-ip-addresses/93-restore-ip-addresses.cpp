class Solution {
public:
    bool isValid(string& s, int start, int end){
        string temp = s.substr(start , end - start + 1);
        int ip = stoi(temp);
        if(temp[0] == '0' && start != end) return false;
        if(ip >= 0 && ip <= 255) return true;
        
        return false;
    }
    void backTrack(string& s,int start, int part,string& sol,vector<string>& res){
        if(start >= s.size() && part == 4){
            res.push_back(sol);
            return;
        }
        
        for(int i = start;i<(int)s.size();i++){
            if(part < 4 && i - start < 3 && isValid(s,start,i)){
                
            sol.append(s.substr(start,i - start + 1));
            
            part++;
            if(part < 4) sol.push_back('.');
            backTrack(s,i+1,part,sol,res);
            if(part<4) sol.pop_back();
            part--;
            
            for(int j = 0;j<i-start + 1;j++) {
                    sol.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string sol = "";
        backTrack(s,0,0,sol,res);
        
        return res;
    }
};