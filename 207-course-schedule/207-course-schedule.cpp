class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& arr) {
        vector<int> adj[V];
        vector<int> indegree(V,0);
        for(auto it : arr){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            V--;
            
            for(auto v : adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        
        return (V == 0);
    }
};