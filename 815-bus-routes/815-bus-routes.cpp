class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> graph;
        //j is stop, i is bus no
        for(int i = 0;i<routes.size();i++){
            for(int j : routes[i]){
                graph[j].push_back(i);
            }
        }
        
        unordered_set<int> seen = {source};
        
        queue<pair<int,int>> q;
        q.push({source,0});
        
        while(!q.empty()){
            int stop = q.front().first;
            int bus = q.front().second;
            q.pop();
            
            if(stop == target) return bus;
            
            
            for(int j : graph[stop]){
                for(int i : routes[j]){
                    if(seen.find(i) == seen.end()){
                        seen.insert(i);
                        q.push({i , bus + 1});
                    }
                }
                routes[j].clear();
            }
        }
        
        return -1;
    }
};