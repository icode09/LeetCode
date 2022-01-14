class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return {};
        
        unordered_map<int,int> mapka;
        for(auto num:nums){
            mapka[num]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it : mapka){
            pq.push({it.second,it.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};