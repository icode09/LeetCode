class Solution {
public:
    struct myComp{
      bool operator()(pair<string,int> const& p1, pair<string,int> const& p2){
          return (p1.second != p2.second) ? p1.second > p2.second : p1.first < p2.first; 
      }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        if(n == 0) return {};
        
        unordered_map<string,int> mapka;
        for(auto str : words){
            mapka[str]++;
        }
        
        priority_queue<pair<string,int> , vector<pair<string,int>> , myComp> pq;
        
        
        for(auto it: mapka){
            pq.push({it.first,it.second});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};