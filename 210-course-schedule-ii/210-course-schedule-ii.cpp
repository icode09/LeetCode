class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it : arr){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
       
        vector<int> topOrder;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            n--;
            topOrder.push_back(u);
            
            for(auto v : adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        
        if(n == 0) return topOrder;
        else return {};
    }
};