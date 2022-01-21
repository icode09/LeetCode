class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool>& visited,vector<bool>& recStack,int u){
        visited[u] = true;
        recStack[u] = true;
        
        for(auto v : adj[u]){
            if(!visited[v]){
                if(dfs(adj,visited,recStack,v)) return true;
            }
            else if(recStack[v]) return true;
        }
        
        recStack[u] = false;
        
        return false;
    }
    bool isCyclic(vector<int> adj[],int V){
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);
        
        for(int i = 0;i<V;i++){
            if(!visited[i])
                if(dfs(adj,visited,recStack,i)) return true;
        }
        
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& arr) {
        // Check cycle in a directed graph
        vector<int> adj[V];
        for(auto it : arr){
            adj[it[1]].push_back(it[0]);
        }
        
        
       return isCyclic(adj,V) ? false : true;
    }
};