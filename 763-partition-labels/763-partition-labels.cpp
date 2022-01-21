class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int> lastSeen(26, 0);
        for(int i = 0; i < s.size(); i++){
            lastSeen[s[i]-'a'] = i;
        }
        
        vector<int> results;
        
        int maxIdx = -1, lastIdx = 0;
        for(int i = 0; i < s.size(); i++){
            maxIdx = max(maxIdx, lastSeen[s[i]-'a']);
            if(i == maxIdx) {
                results.push_back(maxIdx - lastIdx + 1);
                lastIdx = i+1;
            }
        }
        return results;
    }
};