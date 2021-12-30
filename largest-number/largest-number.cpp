class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto val:nums){
            ans.push_back(to_string(val));
        }
        
        sort(ans.begin(),ans.end(),[](string& a,string& b){
            return a + b > b + a;
        });
            
        string res = "";
        for(auto str:ans){
            res += str;
        }
        while(res[0] == '0' && res.size() > 1){
            res.erase(0,1);
        }
        
        return res;
    }
};