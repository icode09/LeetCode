class Solution {
public:
    void dfs(vector<int> adj[],int u, vector<bool>& visited){
        visited[u] = true;
        
        for(auto v : adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> adj[n];
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j && isConnected[i][j])
                    adj[i].push_back(j);
            }
        }
        
        vector<bool> visited(n,false);
        
        int count = 0;
        
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
            }
        }
        
        return count;
    }
};