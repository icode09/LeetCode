class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mapka;
        
        for(auto& path : paths){
            stringstream ss(path);
            string directoryName;
            getline(ss,directoryName,' ');
            
            string s;
            while(ss >> s){
                string fileName = directoryName + '/' + s.substr(0,s.find('('));
                string fileContent = s.substr(s.find('(') + 1,s.find(')') - s.find('(') - 1);
                mapka[fileContent].push_back(fileName);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto it: mapka){
            vector<string> values = it.second;
            if(values.size() > 1){
                ans.push_back(values);
            }
        }
        
        return ans;
    }
};